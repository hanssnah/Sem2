// Data for the "HTML Audio" Page

var audio = {
    controls: true, 
    source: [
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.mp3", type: "audio/mpeg"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.ogg", type: "audio/ogg"}
    ]
};
function audioload(){
    var audiosrc = document.body.querySelector("#audiofile");
    var audiotag = "<audio controls>";
    if(audio.controls === false){
        audiotag = "<audio>";
    }

    for(var i = 0; i<audio.source.length ; i++){
        audiotag += "<source src='" + audio.source[i].src + "' type = '"+ audio.source[i].type + "'>";
    }
    audiotag += "</audio>";
    audiosrc.innerHTML = audiotag;
}