// gpt slop

const express = require('express');
const router = express.Router();
const Account = require('../models/AccountModel');

// Route to get balance
router.get('/balance/:accountId', (req, res) => {
    const accountId = req.params.accountId;

    Account.getBalance(accountId, (err, results) => {
        if (err) return res.json(err);
        if (results.length === 0) return res.status(404).json({ error: 'Account not found' });

        res.json({ Balance: results[0].Balance }); // note uppercase
    });
});

module.exports = router;