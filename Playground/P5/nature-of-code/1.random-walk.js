var points = [];
var colors = [];
const size = 10;

function setup() {
    createCanvas(700, 500);
    background(48);
     for(let i = 0; i < 5; ++i) {
        points[i] = createVector(width / 2, height / 2);
        colors[i] = color(random(150, 250), random(150, 250), random(150, 250));
    }
}

function draw() {    
    for(let i = 0; i < points.length; ++i) {
        fill(colors[i]);
        stroke(colors[i]);        
        randomMove4dir(points[i]);
        // point(points[i].x, points[i].y);
        ellipse(points[i].x, points[i].y, size);
    }
}

function randomMove4dir(p) {
    
    let k = random(0, 1) * 4;
    let step = size / 2;
    if(k <= 1) {
        p.x += -step;
    } else if (k <= 2) {
        p.x += step;
    } else if (k <= 3) {
        p.y += step;    
    } else {
        p.y += -step;    
    }
    
}

function randomMove9dir(p) {

    let k = random(0, 1) * 8;
    let step = size / 2;
    if(k <= 1) {
        p.x += -step;
    } else if (k <= 2) {
        p.x += step;
    } else if (k <= 3) {
        p.y += step;    
    } else {
        p.y += -step;    
    }
}
