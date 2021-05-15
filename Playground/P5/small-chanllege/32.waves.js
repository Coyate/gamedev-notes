let Waves = []
let WaveNum = 10;

function setup() {
    createCanvas(1920, 1080);    
    genWaves();
}

function draw() {
    background(32);       
    
    for (let i = 0; i < WaveNum; ++i) {                
        Waves[i].update();
    }        
    for (let i = 0; i < WaveNum; ++i) {        
        Waves[i].display();
    }        
    
}


function genWaves() {
    if (Waves.length != 0) {
        Waves = [];
    }
    for (let i = 0; i < WaveNum; ++i) {
        // let y = this.A * sin( this.T * x + this.t);  
        Waves[i] = new Wave(
            /* Normal Effects
            random(0.001, 0.05), // T
            random(10, 300), // A
            random(-0.2, 0.5), // t
            random(-150, 150), // yOffset       
            random(0.5, 4), // stoke        
            */
           /* clitch */
           random(0.001, 1), // T
           random(10, 500), // A
           random(-0.01, 0.02), // t
           random(-50, 50), // yOffset       
           random(0.5, 3), // stoke        
            
            color(
                random(50, 150), // R
                random(100, 240), // G
                random(150, 180)  // B
            ))
    }
}

function keyPressed() {
    if (keyCode == 32) {
        genWaves();
    }
}

function mousePressed() {
    genWaves();
}

class Wave {
    constructor(T, A, dt, yOffset, stroke, color) {        
        this.A = A;
        this.T = T;
        this.dt = dt;
        this.t = 0;
        this.yOffset = yOffset;
        this.stroke = stroke;
        this.color = color;        
    }
    
    update() {
        this.wave();
        
    }

    wave() {        
        this.t += this.dt;
    }

    display() {                 
        stroke(this.color, this.stroke / 4 * 255)        

        for(let x = 0; x < width; x+= 1 ) {//x+= 0.25) {
            let y = this.A * sin( this.T * x + this.t);            
            line(x, this.yOffset + height / 2 +  y, x, height / 2 + this.yOffset + y + this.stroke);
        }    
    }
}



/*
// bug gen
let Waves = []
let WaveNum = 10;

function setup() {
    createCanvas(700, 700);    
    for (let i = 0; i < WaveNum; ++i) {
        Waves[i] = new Wave(
            random(0, 1), // T
            random(10, 500), // A
            random(0, 1), // t
            random(0, 1), // stoke        
            color(
                random(50, 150), // R
                random(100, 240), // G
                random(150, 180)  // B
            ))
    }
}

function draw() {
    background(32);       
    
    for (let i = 0; i < WaveNum; ++i) {                
        Waves[i].update();
    }        
    for (let i = 0; i < WaveNum; ++i) {        
        Waves[i].display();
    }        
    
}


class Wave {
    constructor(T, A, dt, stroke, color) {        
        this.A = A;
        this.T = T;
        this.dt = dt;
        this.t = 0;
        this.stroke = stroke;
        this.color = color;        
    }
    
    update() {
        this.wave();
        
    }

    wave() {        
        this.t += this.dt;
    }

    display() {                 
        stroke(this.color, this.stroke * 255)        

        for(let x = 0; x < width; x++) {
            let y = this.A * sin( this.T * x + this.t);            
            line(x, height / 2 +  y, x, height / 2 + y + this.stroke);
        }    
    }
}
*/