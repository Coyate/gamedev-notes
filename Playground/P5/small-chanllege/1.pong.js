function setup() {
    createCanvas(400, 400);
}

function draw() {
    background(0);
    noFill();
    
    strokeWeight(2);
    stroke(0, 100, 200);
    line(width / 2, 0, width / 2, height);

    // lines
    x1 = 0.05;
    y1 = (0.25 + 0.4) / 2;
    x2 =  0.95;
    y2 = (0.75 + 0.9) / 2;

    diffx = x2 - x1;
    diffy = y2 - y1;

    stroke(80);    
    strokeWeight(2);
    stepx = diffx * 0.01;
    stepy = diffy * 0.01;
    
    for (x = x1, y = y1; x < x2 && y < y2; x +=3 * stepx, y += 3 *stepy) {
        line(x * width, y * height, (x + stepx) * width, (y + stepy) * height);;
    }

    // board
    stroke(200, 100, 0);
    strokeWeight(5);
    line(width * 0.05, height * 0.25, width * 0.05, height * 0.4);
    strokeWeight(5);
    line(width * 0.95, height * 0.75, width * 0.95, height * 0.9);
    
    // frame
    stroke(255);
    strokeWeight(3);
    rect(0, 0, width, height);

    // ball
    strokeWeight(1);
    stroke(256);
    fill(220);
    ellipse(width * 0.25, height * 0.44, 10, 10);

}