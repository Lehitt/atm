const mysql = require('mysql2');
const dotenv = require('dotenv');
dotenv.config();
const connection = mysql.createPool(process.env.SQL_SERVER);
module.exports = connection;

//
 connection.query('SHOW TABLES', function(err, result, fields){
    if (err) {
      console.error('Database connection error:', err);
    } else {
      console.log('Database connection successful', result);
    }
}); 
// voi testata toimiiko yhteys databaseen VM:ssä ajamalla node database.js, pitää poistaa testin jälkeen 
