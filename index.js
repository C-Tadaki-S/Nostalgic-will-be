
console.log('Something');

//Variables: The usage is very simillar to C.

let finalPhrase = 'is happening!';
console.log(finalPhrase);

//meaningful
//available
//can't use hifen or space
//firstName
//declare one per line



//Constants = Not changing... in general

const numberOfApples = 10;
console.log ("The number of apples is %d", numberOfApples);




//Atributes = The things that you use.
//  1  - Primitives or Values = copied by value

let number = 10; //number litteral
let phrase = 'Hello World'; //string litteral
let isAccepted = true; //boolean litteral
let collorSelection = null; //nullifier



//  2  - Reference types = copied by address


let first = { value: 15}; //first assigned with the object "value"
let second = first; //second is assigned with the address witch first is assigned

console.log ("The object of first is", first.value);
console.log ("The object of second is", second.value);

//usage of reference type in functions.

let third = {value: 10};

function increase(obj){
obj.value++;
}
increase(third);
console.log("The value of third is now ",third.value);



//Dynamic typing: Can change the type of the variable
 
let numberOfThings = 20;
console.log ("The type of numberofthings is:", typeof numberOfThings);
numberOfThings = 'Twenty';
console.log ("Now the type of numberofthings is:", typeof numberOfThings);
numberOfThings = undefined;
console.log ("Now the type of numberofthings is:", typeof numberOfThings);



//Object properties referencing

person = {
    name: 'Carlos',
    dog: 'Golden Retriever',
    age: 25,
    hairColor: 'dark-brown',
}

console.log (person.name);
console.log (person ['age']);
person ['hairColor'] = 'red';
console.log (person['hairColor']);


//Arrays

let selectedItens = ['tomato', 'cabbage', 'potato'];
selectedItens[3] = 5;
console.log (selectedItens);
console.log (selectedItens.length); //shows us the lenght of an array

//Arrays can expand; they are objects; array.lenght orients it to the number of itens in the array



//functions
//parameters - what is inside a function;  arguments - the input you gave to the function.


function greet (name, dogName){
    console.log('Hello ' + name ,',today is a nice day to walk '+dogName,'!');
}


greet ('John','Fido');

//function examples
// if hour is between 6am and 12pm - good morning;
// if hour is between 12pm and 6pm - good afternoon;


function greetingsHour (hour){
if (hour >= 6 && hour < 12)
    console.log ('Good Morning!');
else if(hour >= 12 && hour <= 18)
    console.log ('Good Afternoon!');
else
    console.log('Good Evening');
}


hour = 3;

greetingsHour(hour);



//loops
function loopCounter(n){
    for(i = 0; i <= n; i++){
        if(i % 2 == 0)
            console.log('This is all the odd numbers:' + i);
    }
}

loopCounter(30);


// Factory functions are used when we need to create a lot of objects

function createCircle (radius){
    return{
        radius, //equals radius = radius,
        draw( ){  //functions inside objects dont need 'function' typing;
            console.log('draw');
        }

    }
}

const circle1 = createCircle (2);
console.log(circle1);
const circle2 = createCircle (4);
console.log(circle2);
const circle3 = createCircle (6);
console.log(circle3);
const circle4 = createCircle (8);
console.log(circle4);

console.log(circle4.draw);


//Constructor Functions








//this keyword
//method (function inside an object)

//this references the object that contains the specified;

const video = {
    playTime: 12,
    playOrNot(){
        console.log(this);
    }
};


function Thing(thingie){
    this.property = thingie;
    console.log(this);
}

const nwThing = new Thing ('breaker');
