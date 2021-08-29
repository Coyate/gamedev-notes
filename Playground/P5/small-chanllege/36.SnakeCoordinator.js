// Train turning and driving according to tires angle
// http://engineeringdotnet.blogspot.com/2010/04/simple-2d-car-physics-in-games.html 


function setup() {
    createCanvas(600, 480);

    // trains
    trains = []
    trainNum = 5;    
    trainMaxSpeed = 4;
    tainMaxSteerAngle = PI / 8;
    
    for (let i = 0; i < trainNum; ++i)  {
        trains[i] = new Train(
            random(0, width),  // x
            random(0, height), // y
            color(random(50, 150), random(80, 240), random(160, 240))); // color
    }

    // planets
    planets = [];
    planetsNum = 4;
    
    for (let i = 0; i < planetsNum; ++i)  {
        planets[i] = new Planet(
            random(50, width - 50),  // x
            random(50, height - 50), // y 
            color(random(150, 250), random(80, 140), random(60, 80)), // color 
            random(60, 100), // radius 
            random(0.01, 0.05) // rotateSpeed
        )                
    }
    
    // player
    flytime = 2.5;

    player = new Player(planets[floor(random(0, planetsNum))]);

}

function draw() {
    background(200);    
    for (let i = 0; i < trainNum; ++i)  {
        trains[i].update();
    }    
    for (let i = 0; i < planetsNum; ++i)  {
        planets[i].update();
    }    
    player.update();
}

// A bicycle model car
class Train {
    constructor(x, y, color) {
        this.pos = createVector(x, y)
        this.color = color;
        this.speed = 0;
        this.headingAngle = - PI / 2;
        this.steerAngle = 0;
        this.wheelBase = 50;
        // p5 env
        this.frameCoff = 45;
        this.direction = random(0, 1) < 0.5; 
        this.width = this.wheelBase * 5 / 7;
        this.height = this.wheelBase * 3.9;       
    }

    update() {
        this.drive();                
        this.updateSpeed()
        this.updatePos()
        this.display()
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

        // friction
        if (this.speed > 0)
            this.speed -= 0.03;
        if (this.speed < 0)
            this.speed += 0.03;
    }

    drive() {
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
            if (this.steerAngle < tainMaxSteerAngle) {
                this.steerAngle += 0.08;
            } else {
                this.steerAngle = tainMaxSteerAngle;
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
            if (this.steerAngle > -tainMaxSteerAngle) {
                this.steerAngle -= 0.08;
            } else {
                this.steerAngle = - tainMaxSteerAngle;
            }
        } else {
            if (this.steerAngle < 0) {
                this.steerAngle += 0.08;
            }
        }
    }

    accel(keydown) {
        if (keydown) {         
            if (this.speed < trainMaxSpeed) {
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
                if (abs(this.speed < trainMaxSpeed))
                    this.speed -= 0.05; // reverse drive
            }
        }
    }


    display() {

        // mainbody        
        push();
        
        // 
        translate(this.pos.x, this.pos.y);
        rotate(this.headingAngle)
        
        rectMode(CENTER);
        noStroke();
        fill(this.color);                
        rect(0, 0, this.height, this.width, 5);        
                
        // wheels        
        fill(100, 200);

        for (let i = 0; i < 8; ++i)  {
            rect(-this.width / 2 + this.height / 8 * (i - 3) + 2, -this.wheelBase / 2 + 8, 15, 8);
            rect(-this.width / 2 + this.height / 8 * (i - 3) + 2, this.wheelBase / 2 - 8, 15, 8);
        }        
        
        // Windows
        // fill(this.color - 0.5);        
        // rect(this.height / 4, 0, this.height / 6 , this.width - 20, 5);        
        // rect(- this.height / 4, 0, this.height / 6 , this.width - 20, 5);
        // rect(0, 0, this.height / 6 , this.width - 20, 5);
        

        pop();
    }
}

class Planet {
    constructor(x, y, color, radius, rotateSpeed) {
        this.pos = createVector(x, y)
        this.color = color;                
        
        this.radius =  radius;
        this.rotateSpeed = rotateSpeed;
    }

    update() {     
        this.display()
    }

    display() {        
        // mainbody
        push();
        
            // rotate(this.headingAngle);
        translate(this.pos.x, this.pos.y);            
        noStroke();
        fill(this.color);                        
        
        ellipse(0, 0, this.radius / 2);
                    
        pop();
    }


}

function mousePressed() {
    player.controller();
}

function circleIntersect(origin, dir, center, radius) {    
    let r = radius;

    let L = p5.Vector.sub(center, origin);
    let tca = p5.Vector.dot(L, dir);
    if (tca < 0)
        return 10000;
    let d2 = p5.Vector.dot(L, L) - tca * tca;
    if (d2 > r) 
        return 10000;
    return tca - sqrt(r - d2);
}

function trainIntersect() {

}

function circularEaseOut(x) {
    let y = sqrt(1 - sq(1 - x));
    return y;
}

class Player {
    constructor(planet) {        
        this.pos = createVector(planet.pos.x + planet.radius, planet.pos.y+ planet.radius);
        this.angle = 0;
        this.isFlying = false;
        this.isDragging = false;   
        this.planet = planet;     
        this.color = color(32, 150, 82);
        this.lineEnder = createVector(0, 0);
        
        this.pointedPlanet = -1;           
        this.flyingStep = 0;      
        this.flyStartPos = createVector(0, 0);
        this.flyEndPos = createVector(0, 0);        
    }

    update() {     
        if(this.isFlying) {
            this.fly();
        } else if (this.isDragging) {

        } else {
            this.updateEnder();
            this.rotateWithPlanet();
        }        
        this.display();
    }


    updateEnder() {        
        let dir = createVector(mouseX - this.pos.x, mouseY - this.pos.y);
        dir.normalize();
        let d = 10000;        
        
        var i = 0;
        // planets intersect
        
        for (i = 0; i < planetsNum; ++i)  {
            let p = planets[i];            
            let d0 = circleIntersect(this.pos, dir, p.pos, p.radius);            
            d = min(d0, d);
            if (d0 != 10000) {                
                this.pointedPlanet = planets[i];
            }                    
        }

        // train intersect
                
        if (d != 10000) {
            this.lineEnder = p5.Vector.add(this.pos, dir.mult(d));
        } else {
            this.lineEnder = createVector(mouseX, mouseY);
            this.pointedPlanet = -1;
        }      
    }


    controller() {
        if (!this.isFlying) {
            if (this.pointedPlanet != -1 && (this.pointedPlanet != this.planet)) {
                this.flyStart();
            }            
            text("fuckaaaaaa", 10, 10);
        } else {            
        }
    }

    flyStart() {        
        this.isFlying = true; 
        this.flyingStep = 0;
        this.flyStartPos = createVector(this.pos.x, this.pos.y);
        this.flyEndPos = createVector(this.pointedPlanet.pos.x, this.pointedPlanet.pos.y);        
        this.angle = p5.Vector.sub(this.flyEndPos, this.flyStartPos).heading() + 3.14;
    }
    
    fly() {        
        if (p5.Vector.dist(this.pos, this.flyEndPos) >= this.pointedPlanet.radius * 0.25 ) {
            this.flyingStep += 1 / (30 * flytime);
            let r = circularEaseOut(this.flyingStep);
            this.pos = p5.Vector.lerp(this.flyStartPos, this.flyEndPos, r, this.pos)            

        } else {
            this.isFlying = false;
            this.planet = this.pointedPlanet;
            
        }

    }

    rotateWithPlanet() {
        this.angle += this.planet.rotateSpeed;
        this.pos.x = this.planet.pos.x + cos(this.angle) * (this.planet.radius / 2);
        this.pos.y = this.planet.pos.y + sin(this.angle) * (this.planet.radius / 2);
    }

    display() {        
        // mainbody        
        push();                
        translate(this.pos.x, this.pos.y);
        rotate(this.angle);

        noStroke();
        fill(this.color);                                
        ellipse(0, 0, 20, 8);                        

        
        pop();                

        stroke(this.color, 200);

        if (!this.isFlying && !this.isDragging)  {
            line(this.pos.x, this.pos.y, this.lineEnder.x, this.lineEnder.y);   
        }
                    
    }

}