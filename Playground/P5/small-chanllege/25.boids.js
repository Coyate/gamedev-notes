// boid 
const boidHistory = 7;
const spawnVec = 1;
const minVec = 0;
const maxVec = 3;
const riskDst = 5;
const nearDst = 100;
const lerpCoef = 0.25;
const cLerpCoef = 0.1;
// Boids
var AllBoids = [];
const boidsNum = 50;
const alignmentCoef = 0.1;
const cohesionCoef = 0.01;
const seperationCoef = -0.5;
// Mouse
const mouseDragCoef = 0.001;
const mouseAwayCoef = -1;
const mouseAwayDst = 50;

function setup() {
    createCanvas(500, 500);
    genboids();
}

function draw() {
    background(48);   
    for(let i = 0; i < AllBoids.length; ++i) {
        AllBoids[i].update();
        AllBoids[i].draw();    
    }
    for(let i = 0; i < AllBoids.length; ++i)
        AllBoids[i].move();
}

function mouseDragged() {
    AllBoids.push(new Boid(mouseX, mouseY));
}

function genboids() {
    if (AllBoids.length != 0) {
        AllBoids = [];
    }
    for(let i = 0; i < boidsNum; ++i) {
        AllBoids[i] = new Boid(random(0, 1) * width, random(0, 1) * height);
    }
}

function keyPressed() {
    if (keyCode == 32) {
        genboids();
    }
}

class  Boid {
    constructor(x, y) {
        this.position = createVector(x, y);
        this.velocity = p5.Vector.random2D().mult(random(0, spawnVec));
        this.neighbors = [];
        this.riskers = [];
        this.newVelocity = p5.Vector.random2D();
        this.histroyPos = [];
        for(let i = 0; i < boidHistory; ++i)
            this.histroyPos[i] = createVector(-1, -1);
        this.color = color(0, 0, 0);
        let r = random(0, 3)
        if (r < 1) {
            this.color = color(random(220, 255), random(40, 100), random(30, 90));
        } else if (r < 2) {
            this.color = color(random(190, 255), random(210, 255), random(70, 100));
        } else {
            this.color = color(random(60, 120), random(200, 255), random(200, 255));
        }
    }

    update() {
        this.getGeighbors();
        this.steering();
        this.draw();
    }

    getGeighbors() {      
        this.neighbors = [];
        this.riskers = [];
        
        let closestDist = 999999999;
        let closestBoid;
        
        for (let i = 0; i < AllBoids.length; ++i) {
            
            let p = AllBoids[i];
            let dist = this.position.dist(p.position);
            
            if (dist < closestDist) {
                closestDist = dist;
                closestBoid = p;
            }
        
            if(dist < nearDst) {
                append(this.neighbors, p);
                if (dist < riskDst) {
                    append(this.riskers, p);
                }
            }
        }
   
        if (this.neighbors.length == 0)
            append(this.neighbors, closestBoid);
        if (this.riskers.length == 0)
            append(this.riskers, closestBoid);
    }

    // o(n ^ 2)
    steering() {
        
        let neighborsCenter = createVector(0, 0);
        let neighborsAvgVec = createVector(0, 0);
        let riskersCenter = createVector(0, 0);
        for (let i = 0; i < this.neighbors.length; ++i) {
            neighborsCenter.add(this.neighbors[i].position);
            neighborsAvgVec.add(this.neighbors[i].velocity);
        }
        
        neighborsCenter.mult(1.0 / this.neighbors.length);
        neighborsAvgVec.mult(1.0 / this.neighbors.length);
        

        for (let i = 0; i < this.riskers.length; ++i) {
            riskersCenter.add(this.riskers[i].position);
        }
        riskersCenter.mult(1.0 / this.riskers.length);

        this.newVelocity = createVector(this.velocity.x, this.velocity.y);

        // Alignment
        this.newVelocity.add(p5.Vector.mult(neighborsAvgVec, alignmentCoef));
        
        // Cohesion
        let neighborsCenterOffset = p5.Vector.sub(neighborsCenter, this.position);
        this.newVelocity.add(p5.Vector.mult(neighborsCenterOffset, cohesionCoef));
        
        // Separation
        let riskersCenterOffset = p5.Vector.sub(riskersCenter, this.position);
        this.newVelocity.add(p5.Vector.mult(riskersCenterOffset, seperationCoef));
        
        // Cursor       
        let mousePos = createVector(mouseX, mouseY);
        let mouseOffset = p5.Vector.sub(mousePos, this.position);
        
        if (mouseOffset.mag() > mouseAwayDst) {
            this.newVelocity.add(p5.Vector.mult(mouseOffset, mouseDragCoef));
        } else {
            this.newVelocity.add(p5.Vector.mult(mouseOffset.normalize(), mouseAwayCoef));
        }
        
    }

    move() {
        this.velocity = p5.Vector.lerp(this.velocity, this.newVelocity, lerpCoef)
        if(this.velocity.mag() > maxVec)
            this.velocity.normalize().mult(maxVec);
        if(this.velocity.mag() < minVec)
            this.velocity.normalize().mult(minVec);
        this.position.add(this.velocity);
        
        if(this.position.x > width)
            this.position.x = 0;
        if(this.position.x < 0)
            this.position.x = width;
        if(this.position.y > height)
            this.position.y = 0;
        if(this.position.y < 0)
            this.position.y = height;
        // history position
        for(let i = 0; i < boidHistory - 1; ++i) {
            this.histroyPos[i].x = this.histroyPos[i + 1].x;
            this.histroyPos[i].y = this.histroyPos[i + 1].y;
        }
        this.histroyPos[boidHistory - 1].x = this.position.x;
        this.histroyPos[boidHistory - 1].y = this.position.y;
    }

    draw() {
        noStroke();
        fill(240, 150);
        // Trail Render
        let step = 255 / boidHistory;
        let alpha = step;
        for (let i = 0; i < boidHistory ; ++i) {
            stroke(this.color, alpha);
            fill(this.color, alpha);
            alpha += step;
            ellipse(this.histroyPos[i].x, this.histroyPos[i].y, i * 2);
        }
        noStroke();
        
        fill(255);
        ellipse(this.position.x, this.position.y, 8);
        let eyePos = p5.Vector.add(this.position, 
            p5.Vector.mult(this.velocity, 0.6));
        fill(10);
        ellipse(eyePos.x, eyePos.y, 3);
    }
}