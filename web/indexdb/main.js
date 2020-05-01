// @ts-nocheck
"use strict";

// In the following line, you should include the prefixes of implementations you want to test.
// window.indexedDB = window.indexedDB || window.mozIndexedDB || window.webkitIndexedDB || window.msIndexedDB;
// DON'T use "var indexedDB = ..." if you're not in a function.
// Moreover, you may need references to some window.IDB* objects:
// window.IDBTransaction = window.IDBTransaction || window.webkitIDBTransaction || window.msIDBTransaction || {READ_WRITE: "readwrite"}; // This line should only be needed if it is needed to support the object's constants for older browsers
// window.IDBKeyRange = window.IDBKeyRange || window.webkitIDBKeyRange || window.msIDBKeyRange;
// (Mozilla has never prefixed these objects, so we don't need window.mozIDB*)

if (!window.indexedDB) {
  console.log("Your browser doesn't support a stable version of IndexedDB. Such and such feature will not be available.");
} else {
  createDB();
}

// This is what our customer data looks like.
const customerData = [
  { ssn: "444-44-4444", name: "Bill", age: 35, email: "bill@company.com" },
  { ssn: "555-55-5555", name: "Donna", age: 32, email: "donna@home.org" }
];

function createDB() {
  const dbName = "the_name";

  let request = indexedDB.open(dbName, 3);
  
  request.onerror = function(_) {
    // Handle errors.
    console.log("Why didn't you allow my web app to use IndexDB!?");
  };
  request.onupgradeneeded = function(event) {
    let db = event.target.result;
  
    db.onerror = function(event) {
      // generic error handler for all errors targeted at this db's requests
      console.error("Database error: ", event.target.errorCode);
    };
  
    // Create an objectStore to hold information about our customers. We're
    // going to use "ssn" as our key path because it's guaranteed to be
    // unique - or at least that's what I was told during the kickoff meeting.
    let objectStore = db.createObjectStore("customers", { keyPath: "ssn" });
  
    // Create an index to search customers by name. We may have duplicates
    // so we can't use a unique index.
    objectStore.createIndex("name", "name", { unique: false });
  
    // Create an index to search customers by email. We want to ensure that
    // no two customers have the same email, so use a unique index.
    objectStore.createIndex("email", "email", { unique: true });
  
    // Use transaction oncomplete to make sure the objectStore creation is 
    // finished before adding data into it.
    objectStore.transaction.oncomplete = function(event) {
      // Store values in the newly created objectStore.
      let customerObjectStore = db.transaction("customers", "readwrite").objectStore("customers");
      customerData.forEach(function(customer) {
        console.log("Adding customer data");
        customerObjectStore.add(customer);
      });
    };
  };
  
}

