const apiKey = "427588dd0c1bd0d694bc07ef5ba5a00b";
const apiUrl = "https://api.openweathermap.org/data/2.5/weather?units = metric&q=";

const searchBox = document.querySelector(".search input")
const searchBtn = document.querySelector(".search button")

async function checkWeather(city){
    const response = await fetch(apiUrl + city + `&appid = ${apiKey}`);
    var data = await response.json();

    console.log(data);


}
searchBtn.addEventListener("click" , () =>{
    checkWeather(searchBox.value);
})
checkWeather();

document.querySelector(".city").innerHTML = data.name;
document.querySelector(".temp").innerHTML = Math.round( data.main.temp) + "°C";
document.querySelector(".humidity").innerHTML = data.main.humidity + "%";
document.querySelector(".wind").innerHTML = data.wind.speed + "km/h";
