/*
 * @name Noise Wave
 * @description Using Perlin Noise to generate a wave-like pattern.
 * Original by Daniel Shiffman.
 */
let yoff;        // 2nd dimension of perlin noise
function setup() {
  createCanvas(512, 400);
  yoff = 0.0;
}

function draw() {
  background(150);

  // We are going to draw a polygon out of the wave points
  beginShape(); 
  
  var xoff = 0;       // Option #1: 2D Noise
  
  // Iterate over horizontal pixels
  for (var x = 0; x <= width; x += 1) {
    let y = map(noise(xoff, yoff), 0, 1, 200, 300);
    let c1 = color(10, 30, 150);
    let c2 = color(10, 250, 200);
    let blue = lerpColor(c1, c2, noise(xoff, yoff));
    stroke(blue);
    line(x, 0, x, y);

    // the bigger the y, the shorter the shadow
    let len = map(y, 200, 300, 12, 1);
    for(let i = 0; i <= len; ++i) {
        stroke(map(i, 0, len, 0, 15), 100);
        point(x, y + i);
    }
    
    xoff += 0.005;
  }
  // increment y dimension for noise
  yoff += 0.01;
  vertex(width, height);
  vertex(0, height);
  endShape(CLOSE);
}
