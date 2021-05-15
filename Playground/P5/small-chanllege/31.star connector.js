let Stars = [];
let starNum = 30;

// size variant
let minSize = 10;
let maxSize = 20;
let sizeStep = 0.5;

let friendDist = 150;



class Star {
    constructor(x, y, s, color) {
        this.x = x;
        this.y = y;
        this.size = s;
        this.color = color;
        this.friends = [];
        this.sizeSign = 1;
        this.dx = random(-1, 1);
        this.dy = random(-1, 1);

    }
    
    update() {
        this.twinkle();
        this.walk();
        this.findFriends();
    }

    twinkle() {        
        this.size += this.sizeSign * sizeStep;
        if (this.size >= maxSize || this.size <= minSize)
            this.sizeSign *= -1;        
    }

    walk() {
        this.x += this.dx;
        this.y += this.dy;

        if (this.x <= 0) {
            this.dx = random(0, 1);
        } else if (this.x >= width) {
            this.dx = random(-1, 0);
        }

        if (this.y <= 0) {
            this.dy = random(0, 1);
        } else if (this.y >= height) {
            this.dy = random(-1, 0);
        }

    }

    findFriends() {
        this.friends = [];
        for (let i = 0; i < starNum; ++i) { 
            let s = Stars[i];
            let d = dist(this.x, this.y, s.x, s.y);
            if (d < friendDist) {                
                stroke(250 - d, 255 - d);
                line(this.x, this.y, s.x, s.y);
            }            
        }

    }

    display() {
        noStroke();
        fill(this.color);        
        ellipse(this.x, this.y, this.size);
    }
}

function setup() {
    createCanvas(700, 700);    
    for (let i = 0; i < starNum; ++i) {
        Stars[i] = new Star(
            random(0, width), random(0, height), random(minSize, maxSize),
            color(
                random(50, 150), // R
                random(100, 240), // G
                random(150, 180)  // B
            ));
    }
}

function draw() {
    background(32);       

    for (let i = 0; i < starNum; ++i) {
        Stars[i].update();
    }        
    for (let i = 0; i < starNum; ++i) {
        Stars[i].display();
    }        
}

