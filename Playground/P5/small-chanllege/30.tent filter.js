function setup() {
    createCanvas(700, 400);
    background(48);
    stroke(255, 20);
}

var radius;
var theta;

function draw() {
    for(var i = 0; i <= 4000; ++i) {
        let x = random(0, 1);
        let y = random(0, 1);     
        let r = 200;   
        point(
            width / 9 +  x * r, 
            height / 4 + y * r);
        
        if (2 * x < 1)
            x = sqrt(2 * x) - 1;
        else
            x = 1 - sqrt(2 - 2 * x);
        
        if (2 * y < 1)
            y = sqrt(2 * y) - 1;
        else
            y = 1 - sqrt(2 - 2 * y);

        x = (x + 1) / 2;
        y = (y + 1) / 2;
        point(
            width  * 5 / 9 +  x * r, 
            height / 4 + y * r);
    }
}