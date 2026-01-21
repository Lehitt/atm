//Vaatii vielä tietokantayhteyden

const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const user = require('../models/user_model');
const jwt = require('jsonwebtoken');

// POST /login
router.post('/', (req, res) => {
  const { cardNumber, pin } = req.body;

  if (!cardNumber || !pin) {
    return res.status(400).json({ message: 'cardNumber or pin missing' });
  }

  user.checkPin(cardNumber, (dbError, dbResult) => {
    if (dbError) {
      return res.status(500).json({ message: 'db_error' });
    }

    if (dbResult.length === 0) {
      return res.status(401).json({ message: 'Invalid credentials' });
    }

    const hashedPin = dbResult[0].pin;

    bcrypt.compare(pin, hashedPin, (err, compareResult) => {
      if (!compareResult) {
        return res.status(401).json({ message: 'Invalid credentials' });
      }

      const token = generateAccessToken(cardNumber);

      return res.json({
        success: true,
        message: 'Login OK',
        cardNumber,
        token,
      });
    });
  });
});

function generateAccessToken(cardNumber) {
  return jwt.sign(
    { cardNumber },
    process.env.MY_TOKEN,
    { expiresIn: process.env.TOKEN_EXPIRES_IN || '900s' }
  );
}

module.exports = router;