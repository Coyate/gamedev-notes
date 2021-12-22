let size = 50;
let add = 0.5;

const Material = {
    Void: 0,
    Sand: 1,
    Water: 2,
    Gas: 3,
}

let PixelWidth = 64;
let PixelHeight = 64;
let ScreenPixel = [];
let ActivePixel = [];



function setup() {
  frameRate(30);
  createCanvas((PixelWidth + 2) * 10, (PixelHeight +2) * 10);  
  for (let x = 0; x < PixelWidth; x++) {
    ScreenPixel[x] = [];      
    for (let y = 0; y < PixelHeight; y++) {
        ScreenPixel[x][y] = Material.Void;
    }
  }  
  for (let x = 0; x < PixelWidth; x++) {  
      for (let y = 0; y < 10; y++) {
        ScreenPixel[x][y+PixelHeight/2] = Material.Water;
      }
  }  
}

function draw() {    
  background(160);    
  Simulation();
  DrawPixels();
  fill(250, 200, 10);
  noStroke();  
  ellipse(width / 2, height / 5, size);  
  size += add;
  if(size > 100 || size < 50) {
    add = -add;  
  }      
}


function DrawPixels() {  
  noStroke();
  for (let x = 1; x < PixelWidth - 1; x++) {        
    for (let y = 1; y < PixelHeight - 1; y++) {
        material = ScreenPixel[x][y];
        if (material == Material.Sand) {
          fill(240, 200, random(50, 150));
          rect(x * 10, y * 10, 10, 10);
        } else if (material == Material.Water) {
          fill(0, 100, 255); 
          rect(x * 10, y * 10, 10, 10);
        } else if (material == Material.Gas) {
          fill(140, 140, 140); 
          rect(x * 10, y * 10, 10, 10);
        }                
    }
  }
}

function Simulation () {  
  for (let x = PixelWidth - 2; x > 0; x -= 1) {        
    // for (let y = 1; y < PixelHeight - 1; y++) {        
    for (let y = PixelHeight - 2; y > 0; y -= 1) {        
        material = ScreenPixel[x][y];
        
    }
  }  
}

function mouseMoved() {
  rect(mouseX, mouseY, 10, 10);
  let x = mouseX / 10;
  let y = mouseY / 10;
  for (let i = -5; i < 5; i++) {
    for (let j = - 5; j < 5; j++) {
      ScreenPixel[x+i][y+j] = Material.Water;  
    }
  }    
}

class Pixel {
  constructor(x, y, material) {
    this.pos = createVector(x, y)    
    this.material = material
    this.active = true;    
  }
  
  update() {
    if (this.material == Material.Sand) {
        this.sand();
    } else if (this.material == Material.Water) {
        this.water();
    } else if (this.material == Material.Gas) {
        this.gas(x, y);
    }               
  }  

  draw() {
    if (this.material == Material.Sand) {
      fill(240, 200, random(50, 150));
      rect(x * 10, y * 10, 10, 10);
    } else if (this.material == Material.Water) {
      fill(0, 100, 255); 
      rect(x * 10, y * 10, 10, 10);
    } else if (this.material == Material.Gas) {
      fill(140, 140, 140); 
      rect(x * 10, y * 10, 10, 10);
    }                
  }
  

  sand() {
    let x = this.pos.y;
    let y = this.pos.x;
    if (ScreenPixel[x][y + 1] == Material.Void) {
      ScreenPixel[x][y + 1] = Material.Sand;
      ScreenPixel[x][y] = Material.Void
    } else if (ScreenPixel[x - 1][y + 1] == Material.Void) {
      ScreenPixel[x - 1][y + 1] = Material.Sand;
      ScreenPixel[x][y] = Material.Void
    } else if (ScreenPixel[x + 1][y + 1] == Material.Void) {
      ScreenPixel[x + 1][y + 1] = Material.Sand;
      ScreenPixel[x][y] = Material.Void
    }  
  }
  
  water() {
    let x = this.pos.y;
    let y = this.pos.x;
    if (ScreenPixel[x][y + 1] == Material.Void) {
      ScreenPixel[x][y + 1] = Material.Water;
      ScreenPixel[x][y] = Material.Void
    } else if (ScreenPixel[x - 1][y + 1] == Material.Void) {
      ScreenPixel[x - 1][y + 1] = Material.Water;
      ScreenPixel[x][y] = Material.Void
    } else if (ScreenPixel[x + 1][y + 1] == Material.Void) {
      ScreenPixel[x + 1][y + 1] = Material.Water;
      ScreenPixel[x][y] = Material.Void
    } else if (ScreenPixel[x - 1][y] == Material.Void) {
      ScreenPixel[x - 1][y] = Material.Water;
      ScreenPixel[x][y] = Material.Void
    } else if (ScreenPixel[x + 1][y] == Material.Void) {
      ScreenPixel[x + 1][y] = Material.Water;
      ScreenPixel[x][y] = Material.Void
    }  
  }
  
  gas() {
    let x = this.pos.y;
    let y = this.pos.x;

    if (ScreenPixel[x][y - 1] == Material.Void) {
      ScreenPixel[x][y - 1] = Material.Gas;
      ScreenPixel[x][y] = Material.Void
    } else if (ScreenPixel[x - 1][y - 1] == Material.Void) {
      ScreenPixel[x - 1][y - 1] = Material.Gas;
      ScreenPixel[x][y] = Material.Void
    } else if (ScreenPixel[x + 1][y - 1] == Material.Void) {
      ScreenPixel[x + 1][y - 1] = Material.Gas;
      ScreenPixel[x][y] = Material.Void
    } else if (ScreenPixel[x - 1][y - 1] == Material.Void) {
      ScreenPixel[x - 1][y - 1] = Material.Gas;
      ScreenPixel[x][y] = Material.Void
    } else if (ScreenPixel[x + 1][y - 1] == Material.Void) {
      ScreenPixel[x + 1][y - 1] = Material.Gas;
      ScreenPixel[x][y] = Material.Void
    }  

    }

}