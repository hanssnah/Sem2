// Data for the "HTML Lists" Page

var fruits = [ "Apples","Oranges","Pears","Grapes","Pineapples","Mangos" ];

var directory = [
    {type: "file", name: "file1.txt"},
    {type: "file", name: "file2.txt"},
    {type: "directory", name: "HTML Files", files: [{type: "file", name: "file1.html"},{type: "file", name: "file2.html"}]},
    {type: "file", name: "file3.txt"},
    {type: "directory", name: "JavaScript Files", files: [{type: "file", name: "file1.js"},{type: "file", name: "file2.js"},{type: "file", name: "file3.js"}]}
];

		var dir_view_innerhtml = "";

		function loaded() {
			loadFruitList();
			loadFileStructure(directory);
			document.body.querySelector("#directory").innerHTML += dir_view_innerhtml;
		}

		function loadFruitList(){
			var fruit = document.body.querySelector("#fruits");
			var fruitvariable = "<ol>";
			for(var i=0; i<fruits.length;i++){
				fruitvariable += "<li>"+ fruits[i]+"</li>";
			}
			fruitvariable += "</ol>";
			fruit.innerHTML += fruitvariable;
			
		}

		function loadFileStructure(dir) {
			dir_view_innerhtml += "<ul>";
				for(var i=0; i< dir.length; i++) {
					if (dir[i].type === 'file') {
						dir_view_innerhtml += "<li>" + dir[i].name +"</li>";
					} else if (dir[i].type === 'directory') {
						dir_view_innerhtml += "<li>" + dir[i].name;
						loadFileStructure(dir[i].files);
						dir_view_innerhtml += "</li>";
					}
				}
			dir_view_innerhtml += "</ul>";
		}
