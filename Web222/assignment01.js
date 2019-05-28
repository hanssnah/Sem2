/********************************
*task 1
*********************************/
//a
var name = 'Hansol Cho',
noc = 6,
program = 'CPA',
job = false,
havejob = '';
//b
console.log('My name is ' + name + ' and I\'m in ' + program + ' program. I\'m taking ' + noc + ' course in this semester.');
//c
if (job === true)
havejob = 'have';
 else
havejob = 'don\'t have';
//d
console.log('My name is ' + name + ' and I\'m in ' + program + ' program. I\'m taking ' + noc + ' course in this semester and I ' + havejob + ' a part-time job now.');
/*********************************
*task 2
**********************************/
//a
var year = 2018;
//b
var useryear = prompt('Please enter your age:');
//c
var birthyear = (year - useryear);
console.log('You were born in the year of ' + birthyear + '.');
//d
var collegeyear = Number(prompt('Enter the number of years you expect to study in the college:'));
//e
var graduate = (year + collegeyear);
console.log('You will graduate from Seneca college in the year of ' + graduate + '.');
/*********************************
*task 3
**********************************/
//a
var Ctem = 50;
//b
var CtoF = function (c) {
  return c * 9 / 5 + 32;
}
console.log(Ctem + '°C is ' + CtoF(Ctem) + '°F.');
//c
var Ftem = 104;
//d
var FtoC = function (f) {
  return ((f - 32) * (5 / 9));
}
console.log(Ftem + '°F is ' + FtoC(Ftem) + '°C.');
/*********************************
*task 4
**********************************/
//a
for (var onetoten = 0; onetoten <= 10; onetoten++) {
  if (onetoten % 2 === 0) {
    console.log(onetoten + ' is even');
  } else {
    console.log(onetoten + ' is odd');
  }
}
/*********************************
*task 5
**********************************/
//a

function largerNum(num1, num2) {
  if (num1 > num2) {
    return num1;
  } 
  else if (num2 > num1) {
    return num2;
  } 
  else {
    return 'same';
  }
} //b

var greaterNum = function (num1, num2) {
  if (num1 > num2) {
    return num1;
  } 
  else if (num2 > num1) {
    return num2;
  } 
  else {
    return 'same';
  }
} //c

var num1 = 5,
num2 = 1,
num3 = 2,
num4 = 10;
console.log('The larger number of ' + num1 + ' and ' + num2 + ' is ' + largerNum(num1, num2));
console.log('The greater number of ' + num3 + ' and ' + num4 + ' is ' + greaterNum(num3, num4));
/*********************************
*task 6
**********************************/
//a
function Evaluator(num1, num2, num3) {
  if (((num1 + num2 + num3) / 3) >= 50) {
    return true;
  } 
  else {
    return false;
  }
}//b

var eva1 = console.log('Average grater than or equal to 50: ' + Evaluator(30, 20, 10));
var eva2 = console.log('Average grater than or equal to 50: ' + Evaluator(80, 55, 11));
var eva3 = console.log('Average grater than or equal to 50: ' + Evaluator(88, 101, 30));
/*********************************
*task 7 
**********************************/
//a
var Grader = function (num7) {
  if (num7 >= 80) {
    return "A";
  } 
  else if (num7 >= 70) {
    return "B";
  } 
  else if (num7 >= 60) {
    return "C";
  } 
  else if (num7 >= 50) {
    return "D";
  } 
  else if (num7 >= 0){
    return "F";
  }
  else {
    return "Not graded";
  }
  
}
var grade1 = console.log('your grade is: ' + Grader(75));
var grade2 = console.log('your grade is: ' + Grader(67));
var grade3 = console.log('your grade is: ' + Grader(98));

/*********************************
*task 8
**********************************/
//a
function showMultiples(num, numMultiples){
  var result;
  for (var i = 1 ; i <= numMultiples ; i++){
    result = num * i;
    console.log(num + " x "+ i + " = " + result);
    
  }
}
//b
 showMultiples(5,4);
 showMultiples(7,5);
 showMultiples(9,2);