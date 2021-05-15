let circles = 1;

function setup() {
    createCanvas(400, 400);
    background(50);
    noStroke();
    frameRate(5);
    circles = 1;
}


function draw(){    
    circles += 1;
    concentricCircle(350, 200, 200, 3);
    concentricCircle(200, 200, 300, circles);
    concentricCircle(100, 100, 100, 5);
}

function concentricCircle(x, y, size, num) {
    greyStep = 255 / num;
    sizeStep = size / num;
    greyScale = 0;
    s = size;
    for(i = 0; i < num; ++i) {
        fill(greyScale + greyStep * i);
        ellipse(x, y, s - sizeStep * i);
    }
}
