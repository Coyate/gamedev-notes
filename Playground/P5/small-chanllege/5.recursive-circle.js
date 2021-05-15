let iteration;
function setup() {
    createCanvas(512, 600);
    noStroke();
    background(72);
    frameRate(1);
    iteration = 0;
}

function draw() {
    iteration += 1;
    if(iteration >= 10)
        iteration = 0;
    drawCircle(400, height / 2, 300, iteration);    
}

function drawCircle(x, y, radius, level) {
    var color = 200 - 128 * level / 4.0;
    fill(color);
    ellipse(x, y, radius * 2);
    if(level >= 1) {
        drawCircle(x, y + radius / 2, radius / 2, level - 1);
        drawCircle(x, y - radius / 2, radius / 2, level - 1);
    }
}
 