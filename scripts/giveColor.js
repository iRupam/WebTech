/*for (var i = 0; i <= 5; i++) {
    var r = Math.floor(Math.random()*255);
    var g = Math.floor(Math.random()*255);
    var b = Math.floor(Math.random()*255);
    var div = document.getElementsByClassName("div")[i].style.backgroundColor = "rgb("+r+","+g+","+b+")";
}
*/
var colours = ['red','blue','green','yellow','cyan','orange'];
var divs = document.getElementsByClassName("div");

function giveColor() {
    console.log("giveColor ran");
    var i;
    for (i = 0; i < divs.length; i++) {
        var newColor = Math.floor(Math.random()*colours.length);
        divs[i].style.backgroundColor = colours[newColor];
    }
}

