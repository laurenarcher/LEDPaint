var canvas = document.getElementById("canvas");
var grids = canvas.children;

paintColor = "black";

for (var j = 0; j < grids.length; j++) {
    var grid = grids[j];

    // when we click on a grid...
    grid.addEventListener("click", function (evt) {
        this.className = paintColor; // give the swatch a class of "blue", which will make the background blue.
    });
}

// swatch interactivity
var palette = document.getElementById("palette");
var swatches = palette.children;
var currentSwatch; // we'll keep track of what swatch is active in this.

for (var i = 0; i < swatches.length; i++) {
    var swatch = swatches[i];
    if (i === 0) {
        currentSwatch = swatch;
    }

    // when we click on a swatch...
    swatch.addEventListener("click", function (evt) {

        this.className = "active"; // give the swatch a class of "active", which will trigger the CSS border.
        currentSwatch.className = ""; // remove the "active" class from the previously selected swatch
        currentSwatch = this; // set this to the current swatch so next time we'll take "active" off of this.

        paintColor = this.style.backgroundColor; // set the background color for the canvas.
        return paintColor

    });
}

// when the clear button is clicked
var clearBtn = document.getElementById("clear");
clearBtn.addEventListener("click", function (evt) {
    grids.className = "white"; // this is all it takes to clear!
});