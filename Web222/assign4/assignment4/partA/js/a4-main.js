var filterType = ""; // sets the filter type to "" (will later be dog, cat or bird)
var filterAgeMin = 0; // sets the filter age min to 0 (for no minimum age filter)
var filterAgeMax = Number.MAX_VALUE; // sets the filter age max to the largest number possible (for no maximum age filter)

var loadTableWithFilters = function () {
    
    var m_tbody = document.body.querySelector("#main-table-body");
    m_tbody.innerHTML = "";
    for (var i = 0; i < petData.length; i++) {
        if (filterType == petData[i].type || filterType == "" && (petData[i].age>=filterAgeMin&&petData[i].age<=filterAgeMax)) {
            var m_tr = document.createElement("tr");

            var m_td = document.createElement("td");
            var m_td2 = document.createElement("td");
            var m_img = document.createElement("img");
            m_img.setAttribute("src", petData[i].image.src);
            m_img.setAttribute("alt", petData[i].image.alt);
            m_img.setAttribute("width", petData[i].image.width);
            m_img.setAttribute("height", petData[i].image.height);
            m_td.appendChild(m_img);
            //m_tr.appendChild(m_td);

            var m_h4 = document.createElement("h4");
            var m_text = document.createTextNode(petData[i].name);
            m_h4.appendChild(m_text);
            m_td2.appendChild(m_h4);

            //m_td = document.createElement("td");
            //m_text = document.createTextNode(petData[i].age);
            //m_td.appendChild(m_text);
            //m_tr.appendChild(m_td);

            //m_td = document.createElement("td");
            m_p = document.createElement("p");
            m_p.innerHTML = petData[i].description;
            m_td2.appendChild(m_p);
            var m_span = document.createElement("span");
            m_text = document.createTextNode("Age: " + petData[i].age +" years old.");
            m_span.appendChild(m_text);
            m_td2.appendChild(m_span);
            //m_tr.appendChild(m_td2);

            //m_td = document.createElement("td");
            //m_text = document.createTextNode(petData[i].type);
            //m_td.appendChild(m_text);
            m_tr.appendChild(m_td);
            m_tr.appendChild(m_td2);

            m_tbody.appendChild(m_tr);
        }
    }

}
var filterDog = function(){
    filterType = "dog";
    loadTableWithFilters();
}

var filterCat = function(){
    filterType = "cat";
    loadTableWithFilters();
}
var filterBird = function(){
    filterType = "bird";
    loadTableWithFilters();
}
var filter_zero_1 = function(){
    filterType = "";
    filterAgeMin = 0;
    filterAgeMax = 1;
    loadTableWithFilters();
}

var filter_1_3 = function(){
    filterType = "";
    filterAgeMin = 1;
    filterAgeMax = 3;
    loadTableWithFilters();
}
var filter_4_plus = function(){
    filterType = "";
    filterAgeMin = 4;
    filterAgeMax = Number.MAX_VALUE;
    loadTableWithFilters();
}


var filterAllPets = function(){
    filterType ="";
    filterAgeMin = 0;
    filterAgeMax = Number.MAX_VALUE;
    loadTableWithFilters();
}
