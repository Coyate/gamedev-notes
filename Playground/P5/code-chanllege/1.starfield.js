let stars = [];
let num_star = 20;

function setup() {
    createCanvas(600, 600);
    num_star = 500;
    for(let i = 0; i < num_star; ++i) {        
        stars[i] = new Star();
    }
}

function draw() {
    background(12);
    translate(width/2, height/2);

    fill(240);    
    for(let i = 0; i < num_star; ++i) {
        stars[i].update();
        stars[i].display();
    }
}


class Star {
    constructor() {
        this.x = random(-width, width);
        this.y = random(-height, height);        
        this.z = random(width);
        this.pz = this.z;      
        this.speed = 0;        
        this.accel = 0.25;
    }

    display() {
                
        let sx = map(this.x / this.z, 0, 1, 0, width);
        let sy = map(this.y / this.z, 0, 1, 0, height);
        let r = map(this.z / width, 0, 1, 8, 0);        

        stroke(200, 100); 

        if (this.pz > this.z) {
            let px = map(this.x / this.pz, 0, 1, 0, width);
            let py = map(this.y / this.pz, 0, 1, 0, height);
            line(px, py, sx, sy);    
        }        

        ellipse(sx, sy, r);
        this.pz = this.z;        
    }

    update() {
        // let speed = map(mouseX, 0, width, 1, 50);
        this.speed +=  this.accel ;
        if (this.speed > 50) {            
            this.accel = -0.5;
        } 
        if (this.speed <= 1) {
            this.accel = 0.25;
        }
        this.z -= this.speed;
        if (this.z < 1) {
            this.x = random(-width/2, width/2);
            this.y = random(-height/2, height/2);
            this.z = width;       
        }
    }

}

