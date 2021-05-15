let drops = [];
let dropsNum = 500;
let wind;
let max_wind = 5;
let windDir = -0.01;
function setup() {
    createCanvas(400, 600);    
    for(let i = 0; i < dropsNum; ++i) {
        drops[i] = new Drop();
    }
    wind = 0;
}

function draw() {
    background(240, 245, 245);    
    wind += windDir * random(10);
    if (wind > 5) {
        windDir = -abs(windDir);
    } else if (wind < -5) {
        windDir = abs(windDir);
    }
        
    for(let i = 0; i < dropsNum; ++i) {
        drops[i].update();
        drops[i].draw();
    }
}

class Drop {
    constructor() {
        this.x = random(-50, width + 50);
        this.y = random(-50, -500);
        this.z = floor(random(10));
        this.speed = map(this.z, 0, 10, 5, 1);
        this.accel = map(this.z, 0, 10, 0.01, 0.0025);
        this.weight = map(this.z, 0, 10, 2, 0.5);
        this.len = map(this.z, 0, 10, 25, 5);      
        this.offset = map(this.z, 0, 10, 0.5, 0.1);  
    }

    update() {
        this.y += this.speed;
        this.x += wind * 0.1;
        this.speed += this.accel;
        if (this.y > height || this.x > width) {
            this.y = random(-50, -500);        
            this.x = random(-50, width + 50);
            this.speed = map(this.z, 0, 20, 5, 1);
        }
    }

    draw() {
        stroke(188, 208, 250);
        strokeWeight(this.weight);              
        
        line(this.x, this.y, this.x + wind * this.offset, this.y + this.len);
    }
}
