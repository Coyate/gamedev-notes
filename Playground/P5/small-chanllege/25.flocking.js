var b;
var boids = [];
const boidSize = 10;
const boidDistance = 20;
const boidAngle = 150;
const boidMaxSpeed = 3;
// ellipse(width / 2, height / 2, 50);


function setup() {
    createCanvas(700, 400);
    stroke(240);
    fill(150);

    
    let pos;
    for(let i = 0; i < 10; ++i) {
        boids[i] = new Boid(width / 2, height / 2);
    }
}

function draw() {
    background(48);
    
    for(let i = 0; i < boids.length; ++i) {
        boids[i].update();
        boids[i].draw();
    }
}

function mouseDragged() {
    boids.push(new Boid(mouseX, mouseY));
  }

class  Boid {
    constructor(x, y) {
        this.position =createVector(x, y);
        this.direction = p5.Vector.random2D();    
        this.acceleration = createVector(0, 0);
        this.velocity = (0, 0);
    }

    update() {
        this.steering();
        this.move();
        this.draw();
    }

    // o(n ^ 2)
    steering() {
        let separationDir = createVector(0, 0);
        let alignmentDir = createVector(0, 0);
        let cohesionPos = createVector(0, 0);

        let neighborNum = 0;
        for(let i = 0; i < boids.length; ++i) {
            let p = boids[i];
            // if(p != this) {  // include this
                
            // detect neighbors
            let dist = this.position.dist(p.position);
            if(dist < boidDistance) { 
                let this2p = p5.Vector.sub(p.position, this.position).normalize();
                let angle = this.direction.angleBetween(this2p);
                if(abs(angle) < radians(boidAngle)) { // neighbors!
                    ++neighborNum;
                    alignmentDir.add(p.direction);
                    cohesionPos.add(p.position);
                    separationDir.add(this2p);
                }
            }
            // }
        }


        separationDir.mult(-1).normalize().mult(1.5);

        alignmentDir.normalize().mult(1);

        cohesionPos.mult(1 / neighborNum);
        let cohesionDir = p5.Vector.sub(cohesionPos.sub(this.position)).normalize().mult(1);
        
        // update direction
        this.direction.add(separationDir).add(alignmentDir).add(cohesionDir).add(createVector(1, 1).mult(0.5)).normalize();
    }

    move() {
        this.position.add(p5.Vector.mult(this.direction, 1));
        
        if(this.position.x < -boidSize / 2)
            this.position.x  = width + boidSize / 2;
        if(this.position.x > width + boidSize / 2)
            this.position.x = - boidSize / 2;
            
        if(this.position.y < -boidSize / 2)
            this.position.y  = height + boidSize / 2;
        if(this.position.y > height + boidSize / 2)
            this.position.y = - boidSize / 2;
    }

    draw() {
        ellipse(this.position.x, this.position.y, boidSize);
    }
}