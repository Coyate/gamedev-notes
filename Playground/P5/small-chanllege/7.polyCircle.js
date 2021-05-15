function setup() {
    createCanvas(500, 500);
}

function draw() {    
    background(96);
    push();
    stroke(255);
    strokeWeight(2);
    fill(250, 210, 0);
    translate(width / 2, height / 2);
    rotate(frameCount / 150);
    var npoints = (int(map(mouseY, 0, height, 3, 10)));
    circleStrip(0, 0, 100, 200, npoints);
    pop();
}

function circleStrip(x, y, in_radius, out_radius, npoints) {
        beginShape(TRIANGLE_STRIP);
        var angleStep = 360 / npoints;
        
        for(var angle = 0; angle <= 361; angle += angleStep) {
            vertex(x + cos(radians(angle)) * out_radius, 
                       y + sin(radians(angle)) * out_radius);
            vertex(x + cos(radians(angle + angleStep / 2)) * in_radius, 
                       y + sin(radians(angle +angleStep / 2)) * in_radius);
        }

        endShape();
}