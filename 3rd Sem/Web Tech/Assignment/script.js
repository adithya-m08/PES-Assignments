var today = new Date();
var dd = today.getDate();
var mm = today.getMonth() + 1;
var yyyy = today.getFullYear();
var hh = today.getHours();
var min = today.getMinutes();
if (dd < 10) {
  dd = "0" + dd;
}
if (mm < 10) {
  mm = "0" + mm;
}
var dt = dd + "/" + mm + "/" + yyyy + " " + hh + ":" + min;
document.getElementById("date-time").innerHTML = dt;
