let n;
let Bars;
let numBar;
let step;

function setup() {
   createCanvas(600, 600);
   Bars = [];
   numBar = 300;
   step = 10;
   for (let i = 0; i < numBar; i++) {
      Bars[i] = new NoiseBar(
         random(0, width),
         random(0, height),
         random(0, 3),
         random(0, 150),

         random(0, 50),
         random(100, 255),
         random(100, 140),
         random(10, 200)
      );
   }

}

function draw() {
   background(0);
   noStroke();
   for (let i = 0; i < numBar; i++) {
      var b = Bars[i];
      b.update();
      b.display();
   }
}

class NoiseBar {

   constructor(x_, y_, w_, h_, r_, g_, b_, a_) {
      this.x = x_;
      this.y = y_;
      this.w = w_;
      this.h = h_;
      this.r = r_;
      this.g = g_;
      this.b = b_;
      this.a = a_;
      this.t = 0;
   }

   update() {
      //x = x + random(-1, 1)*50;
      if (this.x < width / 2) {
         this.y = this.y + step * this.a / 255;
      } else {
         this.y = this.y - step * this.a / 255;
      }
      if (this.y > height + this.h)
         this.y = - this.h;
      if (this.y < -this.h) {
         this.y = height + h;
      }
      //w = w + random(-10, 10);
      this.h = this.h + random(-1, 1);
      this.a = this.a + random(-10, 10);
   }

   display() {
      fill(this.r, this.g, this.b, this.a);
      this.t += 1.0;
      if (this.t >= this.h)
         this.t -= this.h;
      for (let i = 0; i < this.h; ++i) {
         if (this.x < width / 2) {
            let k = i + this.t;
            if (k >= this.h)
               k -= this.h;
            fill(this.r, this.g, this.b, this.a + (255 * k / this.h) - 128);
         } else {
            let k = this.h - i + this.t;
            if (k >= this.h)
               k -= this.h;
            fill(this.r, this.g, this.b, this.a + (255 * k / this.h) - 128);
         }
         rect(this.x, this.y + i, this.w, 1);
      }

   }
}