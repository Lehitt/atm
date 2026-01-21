const db = require('../database'); 

const transactions = {
 
    // tilin kaikki transactionit
  getAllTrans: function(accountId, callback) {
    return db.query(
      'SELECT * FROM Transaction WHERE idAccount = ?',
      [accountId],callback
    );
  },

  // päivämäärän perusteella
  getTransByDate: function(accountId, date, callback) {
    return db.query(
      'SELECT * FROM Transaction WHERE idAccount = ? AND DATE(`Date`) = ?',
      [accountId, date],callback
    );
  },


  depositmoney: function(accountId, amount, callback) {
    
    // päivittää tilin 
    db.query(
      'UPDATE Account SET Balance = Balance + ? WHERE idAccount = ?',
      [amount, accountId],
      (err, result) => {
        if (err) return callback(err);

        // asettaa historiaan transactionin
        db.query(
          "INSERT INTO Transaction (idAccount, Amount, Type, Date) VALUES (?, ?, 'DEPOSIT', NOW())",
          [accountId, amount],
          (err, result) => {
            if (err) return callback(err);

            callback(null, { message: 'Deposit successful' });
          }
        );
      }
    );
  },

  withdrawmoney: function(accountId, amount, callback) {
    
    // tarkistaa account balancen
    db.query(
      'SELECT Balance FROM Account WHERE idAccount = ?',
      [accountId],
      (err, results) => {
        if (err) return callback(err);
        if (results.length === 0) return callback(new Error('Account not found'));

        const currentBalance = results[0].Balance;

        if (currentBalance < amount) {
          return callback(new Error('Insufficient funds'));
        }

        // Insert withdrawal transaction
        db.query(
          "INSERT INTO Transaction (idAccount, Amount, Type, Date) VALUES (?, ?, 'WITHDRAW', NOW())",
          [accountId, amount],
          (err, result) => {
            if (err) return callback(err);

            // päivittää tilin balancen
            db.query(
              'UPDATE Account SET Balance = Balance - ? WHERE idAccount = ?',
              [amount, accountId],
              (err, result) => {
                if (err) return callback(err);

                callback(null, { message: 'Withdrawal successful' });
              }
            );
          }
        );
      }
    );
  }
};

module.exports = transactions;