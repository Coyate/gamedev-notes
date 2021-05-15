let balls = [];
let water;
let G; // gravity
let num_ball;
let deltaTime;

function setup() {
    createCanvas(512, 400);
    G = 9.8;
    water = new Water(0, height / 2, width, height / 2);
    num_ball = 8;
    for(let i = 0; i < num_ball; ++i) {
        balls[i] = new Ball(width * (i + 0.5) / (num_ball), 0, random(20, 50));
    }
}

function draw() {
    background(240);
    water.update();
    water.display();
    for(let i = 0; i < num_ball; ++i) {
        balls[i].update();
        balls[i].display();
    }
}

function mousePressed() {
    for(let i = 0; i < num_ball; ++i) {
        balls[i] = new Ball(width * (i + 0.5) / (num_ball), 0, random(10, 50));
    }
}

class Ball {
    constructor(x, y, r) {
        this.x = x;
        this.y = y;
        this.r = r;    // radius
        this.d = 10;    // density
        this.m = 3 * this.r * this.r / 4 * 1; // mass
        this.F = 0; // Force
        this.v = 0; // velocity
    }

    display() {
        noStroke();
        fill(240, 100, 20);
        ellipse(this.x, this.y, this.r);
    }

    update() {
        // caculate force
        this.F = G * this.m;
        if((this.y + this.r) >= (water.yoff[this.x])) {
            let dragForce = water.C * this.v * this.v;
            if(this.v > 0) 
                dragForce *= - 1.0;
            this.F += dragForce;
        }
            
            
        // caculate speed
        this.v += this.F / this.m / 240;
        
        this.y += this.v;

        // bounce
        if( (this.y + this.r / 2)>= height) {
            this.v = -0.9 * this.v;
            this.y = height - this.r / 2;
        }

    }
}

class Water {
    constructor(x, y, w, h) {
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
        this.C = 2000; // drag Index
        this.yoff = [];
        this.s = 0;
    }
    
    update() {
        this.s += 0.01;
        let s2 = 0;
        for(let i = 0; i < width; ++i) {
            this.yoff[i] = map(noise(this.s, s2), 0, 1, height / 2 - 50, height / 2 + 50);
            s2 += 0.0025;
        }
    }

    display() {
        stroke(20, 120, 200);
        for(let i = 0; i < width; ++i) {
            line(i, this.yoff[i], i, height);
        }
    }
}