var usernameChecker = function() {
    var username = document.querySelector("#username");
    var msg = document.querySelector("#errormsg");
    var lengthchecker = username.value.length;
    var valid = false;
    if(isNaN(username.value.charAt(0))==true){
        valid = true;
        
    }else{
        alert("Error!!");
        msg.innerHTML = "Error is found. Username must be started with a letter.";
        username.focus();
        valid =false;
    }
    if(lengthchecker >= 6){
        valid = true;
    }else{
        alert("Error!!");
        msg.innerHTML = "Error is found. Username must be up to 6 characters.";
        username.focus();
        valid= false;
    }
    
    console.log("usernamecheckeer");
    return valid;
}
var pwchecker = function() {
    var f_password = document.querySelector("#passw");
    var msg = document.querySelector("#errormsg");
    var lengthchecker = f_password.value.length;
    var c_valid = false;
    var u_valid = false;
    var d_valid = false;
    var l_valid = false;
    var character_check = /[a-zA-Z]/g;
    var uppercase = /[A-Z]/g;
    var digits = /[0-9]/g;

    if(f_password.value[0].match(character_check)){
        c_valid = true;
    }else{
        alert("Error!!");
        msg.innerHTML = "Error is found. Password must start with a character.";
        f_password.focus();
        return false;
    }

    if(f_password.value.match(uppercase)){
        u_valid = true;

    }else{
        alert("Error!!");
        msg.innerHTML = "Error is found. Password must have at least 1 uppercase and 1 digit. ";
        f_password.focus();
        return false;
    }

    if(f_password.value.match(digits)){
        d_valid = true;

    }else{
        msg.innerHTML = "Error is found. Password must have at least 1 uppercase and 1 digit. ";
        f_password.focus();
        return false;
    }
    
    if(lengthchecker >= 8){
        l_valid = true;
    }else{
        alert("Error!!");

        msg.innerHTML = "Error is found. Password must be up to 8 characters.";
        f_password.focus();
        return false;
    }
    console.log("pswardcheckeer");
    if(c_valid == true && u_valid == true && d_valid == true && l_valid == true){
        return true;
    }else{
        return false;
    }
}

var repasswordcheck = function(){
    var repsw = document.querySelector("#repassw");
    var ori_pass = document.querySelector("#passw");
    var msg = document.querySelector("#errormsg");
    if(ori_pass.value == repsw.value){
              return true;
    }else{
        alert("Error!");
        msg.innerHTML=("Error is found. Incorrect password.");
        repsw.focus();
        return false; 
    }
    console.log("repasscheckeer");
}

var checker = function(){
    var check1 = usernameChecker();
    var check2 = pwchecker();
    var check3 = repasswordcheck();
    var check4 = zipchecker();

    if(check1==true && check2 == true && check3 == true &&check4==true){
        return true;
    }else{
        return false;
    }
}


var zipchecker = function(){
    var zipvalue = document.querySelector("#zcode");    
    var msg = document.querySelector("#errormsg");
    var valid;
    if(zipvalue.value.match("^[A-Za-z][0-9][A-Za-z][0-9][A-Za-z][0-9]")){
       valid = true;
    }else{
        alert("Error!");
        msg.innerHTML=("Error is found.");
        zipvalue.focus();
        valid =false; 
    }
    return valid;
    console.log(valid+"zipcheckeer");
}