function setup() {
    createCanvas(600, 600);
}

function draw(){
    let bgColor = color(48, 152, 113);    
    background(bgColor);    
    let sdColor = color(48 * 0.8, 152 * 0.8, 113 * 0.8);
    fill(sdColor);
    stroke(sdColor);

    const strip_width = 20;
    for(let x = 0; x < width; ++x) {
        for (let y = 0; y < height; ++y) {

            if ( (x - y % strip_width) % strip_width < strip_width / 2) {                
                line(x, y, x + 1, y); // 上色
            }
            
        }
    }
}
