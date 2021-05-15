function setup() {
    createCanvas(700, 400);
    background(48);
    stroke(255, 20);
}

var radius;
var theta;

function draw() {
    for(var i = 0; i <= 1000; ++i) {
        radius = random(0, 150);
        theta = random(0, PI * 2);
        sqrRadius = random(0, 150 * 150);
        point(
            width / 4 +  radius * cos(theta), 
            height / 2 + radius * sin(theta));
        point(
            width  * 3 / 4 +  sqrt(sqrRadius) * cos(theta), 
            height / 2 + sqrt(sqrRadius) * sin(theta));
        // Triangle
        // point(
        //         width  * 3 / 4 +  sqrt(sqrRadius) * (noise(2.0) - 1.0), 
        //         height / 2 + sqrt(sqrRadius) * sin(theta));
    }
}