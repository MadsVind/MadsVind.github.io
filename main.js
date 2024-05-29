// JavaScript
document.getElementById('openPopup').addEventListener('click', function() {
    document.getElementById('popup').style.display = 'block';
});

document.getElementById('closePopup').addEventListener('click', function() {
    document.getElementById('popup').style.display = 'none';
});

document.getElementById('execute').addEventListener('click', function() {
    var code = document.getElementById('code').value;
    //var output = executeCode(code); // This function should send the code to your interpreter and return the output
    document.getElementById('output').innerHTML = output;
});