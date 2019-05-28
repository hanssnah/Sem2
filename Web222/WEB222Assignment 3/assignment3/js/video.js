// Data for the "HTML Video" Page

var video = {
    controls: true, 
    width: 320,
    height: 240,
    source: [
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.mp4", type: "video/mp4"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.ogg", type: "video/ogg"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.webm", type: "video/webm"}
    ]
};

			function videoload(){
			var videosrc = document.body.querySelector("#firstvideo");
			var videotag = "<video controls width =" + video.width + " height =" + video.height + ">";
			if(video.controls === false){
				videotag = "<video width =" + video.width + " height =" + video.height + ">";
			}
			
			for(var i = 0; i<video.source.length ; i++){
				videotag += "<source src='" + video.source[i].src + "' type = '"+ video.source[i].type + "'>";
			}
			videotag += "</video>";
			videosrc.innerHTML = videotag;
		}
	