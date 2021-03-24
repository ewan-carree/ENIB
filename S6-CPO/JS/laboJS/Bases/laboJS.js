var ex2 = {
    strToInt : function(){
        var var1 = "1";
        var var2 = "2";
        var var3 = var1 + var2;
        console.log(var1, var2, var3);
        console.log(typeof(var1), typeof(var2), typeof(var3));
        
        var1 = parseInt(var1);
        var2 = parseInt(var2);
        var3 = var1 + var2;
        console.log(var1, var2, var3);
        console.log(typeof(var1), typeof(var2), typeof(var3));
    },
    
    Polygone :function(){
        var polygone = {
            var1 : 1,
            var2 : 2,
            var3 : this.var1+this.var2,
            calculAire : function() {
                return this.var1*this.var2
            }
        };
        console.log(polygone.calculAire());
    }
}


function main(){
    ex2.Polygone();
}
main();