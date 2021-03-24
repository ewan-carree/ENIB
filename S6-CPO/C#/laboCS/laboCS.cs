using System;
using System.Collections.Generic;

namespace laboCS {
    // public class Point {
    //     private int _x;
    //     public int X {get; set;}
    //     private int _y;
    //     public int Y {get; set;}

    //     public Point(){
    //         this._x = 10;
    //         this._y = 10;
    //     }
    //     public Point(int x, int y) {
    //         this._x = x;
    //         this._y = y;
    //     }

    //     public double Norme() {
    //         return Math.Sqrt(Math.Pow(this._x, 2) + Math.Pow(this._y, 2));
    //     }
    // }

    // public class Compte{
    //     protected double _solde;
    //     public double Solde {get;}
    //     private int _code;
    //     public int Code {get;}

    //     public Compte() {
    //         this._solde = 0;
    //         this._code = 1111;
    //     }
    //     public Compte(double solde) {
    //         this._solde = solde;
    //         this._code = 1111;
    //     }

    //     public void retrait(int montant) {
    //         this._solde -= montant;
    //     }

    //     public void depot(int montant) {
    //         this._solde += montant;
    //     }

    //     public override string ToString() {
    //         return $"actual amount : {this._solde}";
    //     }
    // }

    // public class CompteEpargne : Compte {
    //     private int _interet;

    //     public CompteEpargne() : base() {
    //         this._interet = 6;
    //     }
    //     public CompteEpargne(double solde) : base(solde) {
    //         this._interet = 6;
    //     }

    //     public void calculInteret() {
    //         this._solde *= 1+(double)this._interet/100;
    //     }
    // }

    // public class ComptePayant : Compte {
    //     private const int price = 5;

    //     public ComptePayant() : base() {

    //     }
    //     public ComptePayant(double solde) : base(solde) {

    //     }

    //     public new void retrait(int montant) {
    //         this._solde -= montant;
    //         this._solde -= price;
    //     }

    //     public new void depot(int montant) {
    //         this._solde += montant;
    //         this._solde -= price;
    //     }

    // }

    // public abstract class Employe {
    //     private int _matricule;
    //     public int Matricule {get; set;}
    //     private string _firstname;
    //     public string FirstName {get; set;}
    //     private string _lastname;
    //     public string LastName {get; set;}
    //     private int[] _birthdate;
    //     public int[] BirthDate {get;}


    //     public Employe() {
    //         this._matricule = 0;
    //         this._firstname = "Default";
    //         this._lastname = "Default";
    //         this._birthdate = new int[3] {1,1,2000};
    //     }
    //     public Employe(int matricule, string firstname, string lastname, int[] birthdate) {
    //         this._matricule = matricule;
    //         this._firstname = firstname;
    //         this._lastname = lastname;
    //         this._birthdate = birthdate;
    //     }

        // public override string ToString() {
        //     return $"{this._firstname} {this._lastname} - {this._birthdate[0]}/{this._birthdate[1]}/{this._birthdate[2]} - matricule : {this._matricule}";
        // }

    //     public abstract double getSalaire();
    // }

    // public class Ouvrier : Employe {
    //     private const int SMIG = 2500;
    //     private int[] _startdate;
    //     public int[] Startdate {get;}

    //     public Ouvrier () : base() {
    //         this._startdate = new int[3] {1,1,2018};
    //     }
    //     public Ouvrier (int matricule, string firstname, string lastname, int[] birthdate, int[] startdate) : base(matricule, firstname, lastname, birthdate) {
    //         this._startdate = startdate;
    //     }

    //     public override string ToString() {
    //         return $"{this.FirstName} {this.LastName} - {this.BirthDate[0]}/{this.BirthDate[1]}/{this.BirthDate[2]} - matricule : {this.Matricule} - startdate in corporation : {this._startdate[2]}";
    //     }

    //     public override double getSalaire() {
    //         int currentYear = DateTime.Now.Year;
    //         double salaire = SMIG + (currentYear-this._startdate[2])*100;
    //         if (salaire > 2*SMIG) {
    //             return 2*SMIG;
    //         }
    //         else {
    //             return salaire;
    //         }
    //     }
    // }

    // public class Cadre: Employe {
    //     private int _indice;
    //     public int Indice {
    //         get {return this._indice;}
    //         set {
    //             if (value >= 1 && value <= 4) {
    //                 this._indice = value;
    //             }
    //         }
    //     }
    //     private double[] _salaryTable = new double[4] {13000, 15000, 17000, 20000};

    //     public Cadre () : base() {
    //         this._indice = 1;
    //     }
    //     public Cadre (int matricule, string firstname, string lastname, int[] birthdate, int indice) : base(matricule, firstname, lastname, birthdate) {
    //         this._indice = indice;
    //     }  

    //     public override double getSalaire() {
    //         return this._salaryTable[this._indice-1];
    //     }      
    // }

    // public class Patron : Employe {
    //     private const int chiffreAffaire = 100000;
    //     public int ChiffreAffaire {get;}
    //     private int _pourcentage;
    //     public int Pourcentage {get; set;}

    //     public Patron () : base() {
    //         this._pourcentage = 10;
    //     }
    //     public Patron (int matricule, string firstname, string lastname, int[] birthdate, int pourcentage) : base(matricule, firstname, lastname, birthdate) {
    //         this._pourcentage = pourcentage;
    //     }  

    //     public override double getSalaire() {
    //         return chiffreAffaire*this._pourcentage/100;
    //     }   

    // }

    public class Personne {
        private string _firstname;
        public string FirstName {get; set;}
        private string _lastname;
        public string LastName {get; set;}
        private int[] _birthdate;
        public int[] BirthDate {get;}

        public Personne() {
            this._firstname = "Default";
            this._lastname = "Default";
            this._birthdate = new int[3] {1,1,2000};
        }
        public Personne(string firstname, string lastname, int[] birthdate) {
            this._firstname = firstname;
            this._lastname = lastname;
            this._birthdate = birthdate;
        }

        public virtual void Afficher() {
            Console.WriteLine($"{this._firstname} {this._lastname} - {this._birthdate[0]}/{this._birthdate[1]}/{this._birthdate[2]}");
        }
    }

    public class Employe2 : Personne {
        private double _salaire;
        public double Salaire {get; set;}

        public Employe2() : base() {
            this._salaire = 1000;
        }
        public Employe2(string firstname, string lastname, int[] birthdate, double salaire) : base(firstname, lastname, birthdate) {
            this._salaire = salaire;
        }

        public override void Afficher() {
            Console.WriteLine($"{this.FirstName} {this.LastName} - {this.BirthDate[0]}/{this.BirthDate[1]}/{this.BirthDate[2]} - salary : {this._salaire}");
        }
    }

    public class Chef : Personne {
        private string _service;
        public string Service {get; set;}

        public Chef() : base() {
            this._service = "RH";
        }
        public Chef(string firstname, string lastname, int[] birthdate, string service) : base(firstname, lastname, birthdate) {
            this._service = service;
        }

        public override void Afficher() {
            Console.WriteLine($"{this.FirstName} {this.LastName} - {this.BirthDate[0]}/{this.BirthDate[1]}/{this.BirthDate[2]} - service : {this._service}");
        }
    }

    public class Directeur : Personne {
        private string _societe;
        public string Societe {get; set;}

        public Directeur() : base() {
            this._societe = "helloWorld";
        }
        public Directeur(string firstname, string lastname, int[] birthdate, string societe) : base(firstname, lastname, birthdate) {
            this._societe = societe;
        }

        public override void Afficher() {
            Console.WriteLine($"{this.FirstName} {this.LastName} - {this.BirthDate[0]}/{this.BirthDate[1]}/{this.BirthDate[2]} - societe : {this._societe}");
        }
    }

    public class Program{
        static void Main(){
            // //Point
            // Point p = new Point(1,2);
            // Console.WriteLine(p.Norme());

            // //Compte
            // Compte c1 = new Compte(1000.0);
            // CompteEpargne c2 = new CompteEpargne(1000.0);
            // ComptePayant c3 = new ComptePayant(1000.0);
            // c1.depot(500);
            // c2.depot(500);
            // c3.depot(500);
            // c1.retrait(100);
            // c2.retrait(100);
            // c3.retrait(100);
            // c2.calculInteret();
            // Console.WriteLine(c1);
            // Console.WriteLine(c2);
            // Console.WriteLine(c3);

            // //Employe
            // Ouvrier p1 = new Ouvrier(1, "Chris", "Froome", new int[3] {4,5,1980}, new int[3] {8,6,2001});
            // Cadre p2 = new Cadre(2, "Julien", "Petit", new int[3] {6,11,1989}, 2);
            // Patron p3 = new Patron(3, "Jean", "Pierre", new int[3] {24,9,1970}, 10);
            // Console.WriteLine($"Salaire ouvrier : {p1.getSalaire()}");
            // Console.WriteLine($"Salaire cadre : {p2.getSalaire()}");
            // Console.WriteLine($"Salaire patron : {p3.getSalaire()}");

            //Personne
            List<Personne> pList = new List<Personne> (8);
            pList.Add(new Employe2("Chris", "Froome", new int[3] {4,5,1980}, 1000));
            pList.Add(new Employe2("Julien", "Petit", new int[3] {6,11,1989}, 1100));
            pList.Add(new Employe2("Jean", "Pierre", new int[3] {24,9,1970}, 1200));
            pList.Add(new Employe2("Anne", "Robert", new int[3] {1,3,2005}, 1300));
            pList.Add(new Employe2("Lou", "Duplantis", new int[3] {2,11,2000}, 1400));
            pList.Add(new Chef("Bilal", "Kouiri", new int[3] {2,11,2000}, "comptabilité"));
            pList.Add(new Chef("Vincent", "Turgis", new int[3] {2,11,2000}, "santé"));
            pList.Add(new Directeur("Antoine", "Martin", new int[3] {6,7,1972}, "Carabreiz"));
            for (int i = 0; i < pList.Count; i++)
            {
                pList[i].Afficher();
            }
            Console.WriteLine();
            foreach(Personne personne in pList){
                personne.Afficher();
            }  
            
        }
    }
}