// Car turning and driving according to tires angle
// http://engineeringdotnet.blogspot.com/2010/04/simple-2d-car-physics-in-games.html 
let car;
let up;
let down;
let left;
let right;
let maxSpeed;
let maxSteerAngle;


function setup() {
  createCanvas(600, 600);
  
  car = new Car(width / 2, height * 3 / 4, color(224, 180, 40));
  
  up = false;
  down = false;
  left = false;
  right = false;

  maxSpeed = 7;
  maxSteerAngle = PI / 8;
}

function draw() {
  background(200);  
  car.update();
}


// A bicycle model car
class Car {
  constructor(x, y, color) {
    this.pos = createVector(x, y)    
    this.color = color;    
    this.speed = 0;
    this.headingAngle = - PI / 2;
    this.steerAngle = 0;
    this.wheelBase = 50;
    // p5 env
    this.frameCoff = 45;
  }

  updateSpeed() {  
    if (keyIsDown(32)) {
      car = new Car(width / 2, height * 3 / 4, color(224, 180, 40));
    }
    fill(72);
    if (keyIsDown(68)) {  // d right    
      ellipse(width - 10, height / 2, 10);         
      
      if(this.steerAngle < maxSteerAngle) {
        this.steerAngle += 0.08;
      } else {
        this.steerAngle = maxSteerAngle;
      }
    } else {
      if(this.steerAngle > 0) {
        this.steerAngle -= 0.08;
      }
    }
    if (keyIsDown(65)) {  // a left    
      ellipse(10, height / 2, 10);
      if(this.steerAngle > -maxSteerAngle) {
        this.steerAngle -= 0.08;
      } else {
        this.steerAngle = - maxSteerAngle;
      }
    } else {
      if (this.steerAngle < 0) {
        this.steerAngle += 0.08;
      }
    }
    if (keyIsDown(87)) {      // w      
      ellipse(width / 2, 10, 10);
      if(this.speed < maxSpeed) {
        this.speed += 0.08;
      }      
    }
    if (keyIsDown(83)) {  // d   
      ellipse(width / 2, height - 10, 10);   
      if(this.speed > 0) {
        this.speed -= 0.15; // brake
      } else {
        if (abs(this.speed < maxSpeed))
          this.speed -= 0.05; // reverse drive
      }
    }    

    if (this.speed > 0) 
      this.speed -= 0.02;
    if (this.speed < 0)
      this.speed += 0.02;
  }

  updatePos(){
    
    // get wheel pos
    this.headingAxis = createVector(cos(this.headingAngle), sin(this.headingAngle));
    this.frontWheel = p5.Vector.add(this.pos, p5.Vector.mult(this.headingAxis, this.wheelBase / 2));
    this.rearWheel = p5.Vector.add(this.pos, p5.Vector.mult(this.headingAxis, - this.wheelBase / 2)); 

    

    // wheeling forward
    this.steerAxis = createVector(cos(this.headingAngle + this.steerAngle), sin(this.headingAngle + this.steerAngle));
    this.frontWheel.add(p5.Vector.mult(this.steerAxis, this.speed * this.frameCoff / frameRate()));
    this.rearWheel.add(p5.Vector.mult(this.headingAxis, this.speed * this.frameCoff / frameRate()));

    // new pos
    this.pos = p5.Vector.add(this.frontWheel, this.rearWheel).mult(0.5);
    this.headingAngle = atan2(this.frontWheel.y - this.rearWheel.y, this.frontWheel.x - this.rearWheel.x);
    
    if (this.pos.x > width) {
      this.pos.x = 0;
    } else {
      if (this.pos.x < 0) {
        this.pos.x = width;
      }
    }
    if (this.pos.y > height) {
      this.pos.y = 0;
    } else {
      if (this.pos.y < 0) {
        this.pos.y = height;
      }
    }
  }


  display() {
    
    let carWidth = this.wheelBase * 5 / 7;
    let carHeight = this.wheelBase * 1.2;
    // mainbody
    push();    
    // rotate(this.headingAngle);
    translate(this.pos.x, this.pos.y);
    rotate(this.headingAngle)
    rectMode(CENTER);
    fill(this.color);    
    strokeWeight(2);
    stroke(180, 120, 10);        
    rect(0, 0, carHeight, carWidth, 5);

    fill(this.color, 150);    
    strokeWeight(2);
    stroke(180, 120, 10, 150);        
    rect(0, 0, carHeight - 5, carWidth - 4, 5);    
    // rearwheel
    fill(100, 50);
    noStroke();    
    rect(-carWidth / 2, 0, 3, 25);
    fill(100);
    rect(-carWidth / 2, -this.wheelBase / 2 + 8, 15, 8);
    rect(-carWidth / 2, this.wheelBase / 2 - 8, 15, 8);

      // frontwheel                
      push();
      fill(100, 50);
      rect(carWidth / 2, 0, 3, 25);
      fill(100);
        push();
        translate(carWidth / 2, -this.wheelBase / 2 + 8);
        rotate(this.steerAngle);
        rect(0, 0, 15, 8);      
        pop();
        
        push();      
        translate(carWidth / 2, this.wheelBase / 2 - 8);
        rotate(this.steerAngle);
        rect(0, 0, 15, 8);      
        pop();
      pop();

  pop();
  }


  update(){
    
    this.updateSpeed()
    this.updatePos()    
    this.display()
  }
}
