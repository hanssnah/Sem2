/*********************************************************************************
*  WEB222 – Assignment 02
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  
*  No part of this assignment has been copied manually or electronically from any other source
*  (including web sites) or distributed to other students.
* 
*  Name: ____Hansol______Cho_____________ Student ID: __103608170______________ Date: _____Feb.19.2018___________
*
********************************************************************************/ 


var allData = [
    {type:"store", data:{store_id: 297, name: "Scotiabank - Main Branch", address_id: 1023}},
    {type:"store", data:{store_id: 614, name: "Scotiabank - Hamilton", address_id: 1984}},
    {type:"store", data:{store_id: 193, name: "Scotiabank - Mississauga", address_id: 1757}},
    {type:"customer", data:{customer_id: 26, store_id:297, first_name: "Dave", last_name: "Bennett", email: "dbennett@gmail.com", address_id: 4536, add_date: null}},
    {type:"customer", data:{customer_id: 59, store_id:193, first_name: "John", last_name: "Stevens", email: "jstevens22@hotmail.com", address_id: 2473, add_date: null}},
    {type:"customer", data:{customer_id: 29, store_id:614, first_name: "Sarah", last_name: "Pym", email: "spym99@hotmail.com", address_id: 1611, add_date: null}},
    {type:"customer", data:{customer_id: 63, store_id:297, first_name: "Steven", last_name: "Edwards", email: "steven2231@hotmail.com", address_id: 1836, add_date: null}},
    {type:"customer", data:{customer_id: 71, store_id:614, first_name: "Martin", last_name: "Scott", email: "mdog33@gmail.com", address_id: 2727, add_date: null}},
    {type:"customer", data:{customer_id: 24, store_id:614, first_name: "Jonathan", last_name: "Pym", email: "jjpym@yahoo.ca", address_id: 1611, add_date: null}},
    {type:"customer", data:{customer_id: 36, store_id:193, first_name: "Kaitlyn", last_name: "Adams", email: "katy38@hotmail.com", address_id: 5464, add_date: null}},
    {type:"customer", data:{customer_id: 73, store_id:297, first_name: "Melissa", last_name: "Bennett", email: "mbennett@gmail.com", address_id: 4536, add_date: null}},
    {type:"address", data:{address_id: 1023, address: "2895 Yonge St.", city:"Toronto", province:"ON", postal_code:"L4C02G"}},
    {type:"address", data:{address_id: 1984, address: "3611 Main St. West", city:"Hamilton", province:"ON", postal_code:"R5O8H5"}},
    {type:"address", data:{address_id: 1757, address: "1177 Ontario St. Unit 8", city:"Mississauga", province:"ON", postal_code:"L9H6B3"}},
    {type:"address", data:{address_id: 4536, address: "3945 John St.", city: "Ajax", province: "ON", postal_code: "L7M4T9"}},
    {type:"address", data:{address_id: 2473, address: "391 Baker St. Apt 231", city: "Mississauga", province: "ON", postal_code: "M4T8S3"}},
    {type:"address", data:{address_id: 1611, address: "183 City Ct.", city: "Hamilton", province: "ON", postal_code: "J3T9V2"}},
    {type:"address", data:{address_id: 1836, address: "67 Rhymer Ave.", city: "Stouffville", province: "ON", postal_code: "L3C8H4"}},
    {type:"address", data:{address_id: 2727, address: "287 Brant St. Apt 4A", city: "Waterdown", province: "ON", postal_code: "R93G3P"}},
    {type:"address", data:{address_id: 5464, address: "11 New St. Apt 2B", city: "Brampton", province: "ON", postal_code: "L694R7"}},
];

var CustomerDB = new function() {
  this.customers = Array();
  this.addresses = Array();
  this.stores = Array();
}

CustomerDB.insertData = function (allData) {

  for (var i  = 0; i < allData.length; i++) {
    
    if (allData[i]["type"] == "store") {
      CustomerDB.addStore(allData[i]);
      
    } else if (allData[i]["type"] == "customer") {
      CustomerDB.addCustomer(allData[i]);
      
    } else if (allData[i]["type"] == "address") {
      CustomerDB.addAddress(allData[i]);
    }
  }
}

CustomerDB.addCustomer = function (customerObj) { //set "add_date" to current date
  var currentDate = new Date();
  customerObj["data"]["add_date"] = currentDate;
  this.customers.push(customerObj);
}

CustomerDB.outputAllCustomers = function () {
  console.log("All Customers");
  
  for (var i  = 0; i < this.customers.length; i++) {
   
    CustomerDB.outputCustomerById(this.customers[i]["data"]["customer_id"]);
  }
}

CustomerDB.outputCustomerById = function (customer_id) {

  for (var i  = 0; i < this.customers.length; i++) {
    var customerObj = this.customers[i]["data"];
    
    if (customerObj["customer_id"] == customer_id) {
      console.log("\nCustomer " + customerObj["customer_id"] + ": " + customerObj["first_name"] + " " + customerObj["last_name"] + " (" + customerObj["email"] + ") ");

      var addressObj = CustomerDB.getAddressById(customerObj["address_id"]);
      console.log("Home Address: " + addressObj["data"]["address"] + " " + addressObj["data"]["city"] + ", " + addressObj["data"]["province"] + ". " + addressObj["data"]["postal_code"]);
     
      console.log("Joined: " + customerObj["add_date"] + "\n");
    }
  }
}

CustomerDB.outputCustomersByStore  = function (store_id) {
 
  var storeObj = CustomerDB.getStoreById(store_id);
  console.log("Customers in Store: " + storeObj["data"]["name"]);

  for (var i = 0; i < this.customers.length; i++) {
    var customerObj = this.customers[i]["data"];
  
    if (customerObj["store_id"] == store_id) {
      CustomerDB.outputCustomerById(customerObj["customer_id"] + "\n");
    }
  }
  console.log("\n");
}

CustomerDB.removeCustomerById = function (customer_id) {

  var valid = false;
  var valid_num = 0;

  for (var i = 0; i < this.customers.length; i++) {
    if (customer_id == this.customers[i]["data"]["customer_id"]) {
      Find = true;
      valid_num = i;
    }
  }

  if (valid) {
    CustomerDB.removeAddressById(this.customers[num]["data"]["address_id"]);
  }

  this.customers.splice(valid_num, 1);
}

CustomerDB.addStore = function (storeObj) {
  this.stores.push(storeObj);
}

CustomerDB.getStoreById = function (store_id) {
  
  var valid_num = 0;
 
  for (var i = 0; i < this.stores.length; i++) {
    var storeObj = this.stores[i]["data"];
 
    if (storeObj["store_id"] == store_id) {
      num = i;
    }
  }
  return this.stores[valid_num];
}

CustomerDB.outputAllStores = function () {
  console.log("All Stores\n");
 
  for (var i  = 0; i < this.stores.length; i++) {
    var storeObj = this.stores[i]["data"]; 
    var locationObj = CustomerDB.getAddressById(storeObj["address_id"]);
    var locationObj = locationObj["data"];

    console.log("\nStore " + storeObj["store_id"] + ": " + storeObj["name"] + "\n");
    console.log("Location: " + locationObj["address"] + " " + locationObj["city"] + ", " + locationObj["province"] + " " + locationObj["postal_code"]);
  }
}

CustomerDB.addAddress = function (addressObj) {
  this.addresses.push(addressObj);
}

CustomerDB.outputAllAddresses = function () {
  console.log("All Addresses");
  
  for (var i  = 0; i < this.addresses.length; i++) {
    
    //Printing address
    var addrObj = this.addresses[i]["data"];
    console.log("\nAddress " + addrObj["address_id"] + ": " + addrObj["address"] + " " + addrObj["city"] + ", " + addrObj["province"] + ". " + addrObj["postal_code"] + "\n");
  }
}

CustomerDB.getAddressById = function (address_id) {
  var valid_num = 0;
 
  for (var i = 0; i < this.addresses.length; i++) {
    var addressObj = this.addresses[i];
 
    if (addressObj["data"]["address_id"] == address_id) {
      valid_num = i;
    }
  }
  return this.addresses[valid_num];
}

CustomerDB.removeAddressById = function (address_id) {
 
  var c_addr = 0;
  var num = 0;
  var valid = false;

  for (var i = 0; i < this.addresses.length; i++) {
    var addrObj = this.addresses[i]["data"];
    
    if (addrObj["address_id"] == address_id) {
      c_addr++;
      
      if (c_addr== 1) {
        if (address_id != 4536) { 
          num = i;
          valid = true;
        }
      }
    }
  }

  if (valid) {
    
    var s_exi = false;
    var c_addr_exi = false;
    var compareAddress = address_id;

    for (i  = 0; i < this.stores.length; i++) {
      
      if (compareAddress == this.stores[i]["data"]["address_id"]) {
        s_exi = true;
        
      }
    }
    for (i  = 0; i < this.customers.length; i++) {
      
      if (compareAddress == this.customers[i]["data"]["address_id"]) {
        if (i != num) {
          c_addr_exi = true;
        }
      }
    }

    if (s_exi != false || c_addr_exi != false) {
      this.addresses.splice(num, 1);
    }
  }
}



CustomerDB.insertData(allData);

console.log("CustomerDB.outputAllCustomers();\n\n--------------------------\n\n");
CustomerDB.outputAllCustomers();
console.log("--------------------------\n\n");

console.log("CustomerDB.outputAllAddresses();\n\n--------------------------\n\n");
CustomerDB.outputAllAddresses();
console.log("--------------------------\n\n");

console.log("CustomerDB.outputAllStores();\n\n--------------------------\n\n");
CustomerDB.outputAllStores();
console.log("--------------------------\n\n");

console.log("CustomerDB.outputCustomersByStore(297);\n\n--------------------------\n\n");
CustomerDB.outputCustomersByStore(297);
console.log("--------------------------\n\n");

console.log("CustomerDB.removeCustomerById(26);\nCustomerDB.removeCustomerById(71);\n\n");
CustomerDB.removeCustomerById(26);
CustomerDB.removeCustomerById(71);
console.log("--------------------------\n\n");

console.log("CustomerDB.outputAllCustomers();\n\n--------------------------\n\n");
CustomerDB.outputAllCustomers();
console.log("--------------------------\n\n");

console.log("CustomerDB.outputAllAddresses();\n\n--------------------------\n\n");
CustomerDB.outputAllAddresses();
console.log("--------------------------\n\n");

/*
Exception: SyntaxError: expected expression, got ']'
@Scratchpad/3:41
*/