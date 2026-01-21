const express = require('express');
const router = express.Router();
const transactions = require('../models/TransactionModel');

router.get('/Transaction/getAllTrans/:accountId', (req, res) => {
 const accountId = req.params.accountId;

    transactions.getAllTrans(accountId, function(err, dbResult) {
        if (err) {
            console.log("getAlltrans failed (Transaction.js)", err);
            res.json(err);
        } else {
            console.log(dbResult);
            res.json(dbResult);
        }
    }); 
}); 

router.get ('/Transaction/getTransByDate/:accountId/:date', (req, res) => {
 const accountId = req.params.accountId;
    const date = req.params.date;

        transactions.getTransByDate(accountId,date,(err, dbResult) => {
            if (err) {
                console.log("getTransByDate failed (Transaction.js)", err);
                res.json(err);
            } else {
                console.log(dbResult);
                res.json(dbResult);
            }
    });
});


router.post ('/Transaction/depositmoney/:accountId/:amount', (req,res) => {
    const accountId = req.params.accountId;
    const amount = req.params.amount;

    transactions.depositmoney(accountId, amount, (err, dbResult) => {

        if (err) {
                console.log("depositmoney failed (Transaction.js)", err);
                res.json(err);
            } else {
                console.log(dbResult);
                res.json(dbResult);
            }
    });
});



// withdraw = post



module.exports = router;