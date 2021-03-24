using System;

namespace laboCS {
    public class Point {
        private int _x;
        public int X {get; set;}
        private int _y;
        public int Y {get; set;}

        public Point(){
            this._x = 10;
            this._y = 10;
        }
        
        public Point(int x, int y) {
            this._x = x;
            this._y = y;
        }

        public float Norme() {
            return Math.Sqrt(Math.Pow(this._x, 2) + Math.Pow(this._y, 2));
        }

        static void Main(){
            Point p1 = new Point(1,2);
            Console.WriteLine(p1.Norme());
        }
    }
}