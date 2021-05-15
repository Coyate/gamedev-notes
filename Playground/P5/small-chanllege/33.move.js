let horizontal;
let vertical;
let x;
let y;
let h;
let speed;
let maxSpeed;
let momentum;
let maxMomentum;
let friction;

function setup() {
    createCanvas(700, 700);    
    
    horizontal = 0;
    vertical = 0;
    h = 20;
    x = width / 2;
    y = height / 2;
    speed = 1;    
    maxSpeed = 10;
    momentum = 0;
    maxMomentum = 10;
    friction = 5;
}

function draw() {
    background(32);      
    stroke(72);
    fill(220, 182, 120);
    rect(0, height / 2 + 20, width, height);    
        
    update();
    
    fill(105, 235, 195);
    ellipse(x, y - h, h, h * 2);
}


function update() {
    
    momentum += horizontal;    
    momentum = clamp(momentum, 0, maxMomentum);
    speed += momentum;
    speed = clamp(speed, 0, maxSpeed);

    x += horizontal * speed;
    y += vertical * speed;
}

function clamp(n, min, max) {
    if (n > max) 
        n = max;
    if (n < min)
        n = min
    return n;
}


function keyPressed() {    
    switch(keyCode) {
        case(37) : // Left 
        case(65) : // A
        horizontal = -1; break;
        case(39) : // Right
        case(68) : // D
        horizontal = 1; break;
        case(38) : // Up 
        case(87) : // W
        vertical = -1; break;        
        case(40) : // Down        
        case(83) : // S
        vertical = 1; break;        
    }
    if (keyCode == 32)           {
        x = width / 2;
        y = height / 2;
    }
}

function keyReleased() {
    switch(keyCode) {
        case(37) : // Left 
        case(65) : // A
        horizontal = 0; break;
        case(39) : // Right
        case(68) : // D
        horizontal = 0; break;
        case(38) : // Up 
        case(87) : // W
        vertical = 0; break;        
        case(40) : // Down        
        case(83) : // S
        vertical = 0; break;        
    }
}