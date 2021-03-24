var individu = {
    Taille : "1.78m",
    Poids : "68kg",
    Age : "21 ans",
    Yeux : "noisette",
    Cheveux : "bruns",

    getAge : function() {return this.Age;}
};

console.log(individu.getAge());

var acteur = {
    nom : "Dujardin",
    peutparler : true,

    tirade : function(texte) {console.log(this.nom + " : " + texte);}
};

acteur.tirade("Ma blanquette est bonne");

//var acteurMuet



