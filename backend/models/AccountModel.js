// gpt slop


const db = require('../database');

const Account = {
  // Get balance for a specific account
  getBalance: function(accountId, callback) {
    db.query(
      'SELECT Balance FROM Account WHERE idAccount = ?',
      [accountId],
      callback
    )
  }
}

module.exports = Account;