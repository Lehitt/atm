const db = require('../database');

const user = {
  checkPin: function (cardNumber, callback) {
    return db.query(
      'SELECT * FROM users WHERE cardNumber = ?',
      [cardNumber],
      callback
    );
  }
};

module.exports = user;