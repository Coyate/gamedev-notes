// Car turning and driving according to tires angle
// http://engineeringdotnet.blogspot.com/2010/04/simple-2d-car-physics-in-games.html 
let car;
let KEY_UP;
let down;
let left;
let right;
let maxSpeed;
let maxSteerAngle;

let trains;
let carNum;

function setup() {
    createCanvas(1024, 768);

    trains = []
    carNum = 5;

    for (let i = 0; i < carNum; ++i)  {
        trains[i] = new Car(random(0, width), random(0, height), 
        color(random(50, 150), random(80, 240), random(160, 240)),
        false, // manual control
        random(0, 0.05));
    }

    // car = new Car(width / 2, height * 3 / 4, color(224, 180, 40), true, 1);
    // Cars[carNum] = car;
    KEY_UP = false;
    down = false;
    left = false;
    right = false;

    maxSpeed = 4;
    maxSteerAngle = PI / 8;
}

function draw() {
    background(200);
    // car.update();
    for (let i = 0; i < carNum; ++i)  {
        trains[i].update();
    }
}

// A bicycle model car
class Car {
    constructor(x, y, color, manual, grav) {
        this.pos = createVector(x, y)
        this.color = color;
        this.speed = 0;
        this.headingAngle = - PI / 2;
        this.steerAngle = 0;
        this.wheelBase = 50;
        // p5 env
        this.frameCoff = 45;
        this.manual = manual;
        this.direction = random(0, 1) < 0.5;
        this.grav = grav;
    }

    update() {
        this.updateSpeed()
        this.updatePos()
        this.gravity();
        this.display()
    }

    gravity() {
        for(let i = 0; i < carNum; ++i) {
            let dist = p5.Vector.dist(trains[i].pos, this.pos);
            trains[i].pos = p5.Vector.lerp(trains[i].pos, this.pos, this.grav / dist);            
        }
    }

    updatePos() {

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



    updateSpeed() {
        if (this.manual) {
            this.manualControl();
        } else {
            this.autoControl();
        }

        // friction
        if (this.speed > 0)
            this.speed -= 0.02;
        if (this.speed < 0)
            this.speed += 0.02;
    }

    manualControl() {
        if (keyIsDown(32)) {
            car = new Car(width / 2, height * 3 / 4, color(224, 180, 40));
        }
        fill(72);

        this.turnRight(keyIsDown(68));        
        this.turnLeft(keyIsDown(65));
        this.accel(keyIsDown(87));   
        this.brake(keyIsDown(83));
    }

    autoControl() {
        if ( random(0, 1) > random(0, 1) ) {
            this.turnRight(true);
        } else {
            this.turnLeft(true);
        }        
        this.accel(true);   
        this.brake(keyIsDown(83));
    }

    turnRight(keydown) {
        if (keydown) {
            if (this.steerAngle < maxSteerAngle) {
                this.steerAngle += 0.08;
            } else {
                this.steerAngle = maxSteerAngle;
            }
        } else {
            if (this.steerAngle > 0) {
                this.steerAngle -= 0.08;
            }
        }
    }
    
    turnLeft(keydown) {
        if (keydown) {  // a left    
            // ellipse(10, height / 2, 10);
            if (this.steerAngle > -maxSteerAngle) {
                this.steerAngle -= 0.08;
            } else {
                this.steerAngle = - maxSteerAngle;
            }
        } else {
            if (this.steerAngle < 0) {
                this.steerAngle += 0.08;
            }
        }
    }

    accel(keydown) {
        if (keydown) {         
            if (this.speed < maxSpeed) {
                this.speed += 0.08;
            }
        }        
    }

    brake(keydown) {
        if (keydown) {
            // ellipse(width / 2, height - 10, 10);   
            if (this.speed > 0) {
                this.speed -= 0.15; // brake
            } else {
                if (abs(this.speed < maxSpeed))
                    this.speed -= 0.05; // reverse drive
            }
        }
    }


    display() {
        let carWidth = this.wheelBase * 5 / 7;
        let carHeight = this.wheelBase * 3.9;
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
        rect(0, 0, carHeight - 8, carWidth -4, 5);
        
        fill(this.color, 50);        
        rect(carHeight / 4, 0, carHeight / 6 , carWidth - 20, 5);        
        rect(- carHeight / 4, 0, carHeight / 6 , carWidth - 20, 5);
        rect(0, 0, carHeight / 6 , carWidth - 20, 5);
        

        // rearwheel
        fill(100, 50);
        noStroke();        
        fill(100, 200);

        for (let i = 0; i < 8; ++i)  {
            rect(-carWidth / 2 + carHeight / 8 * (i - 3) + 2, -this.wheelBase / 2 + 8, 15, 8);
            rect(-carWidth / 2 + carHeight / 8 * (i - 3) + 2, this.wheelBase / 2 - 8, 15, 8);
        }

        
        

        // frontwheel                
        
        pop();
        pop();
        pop();
    }



}
