

let blobArray = [{type: "img",
                  href: "https://github.com/MadsVind", 
                  title: "Github link to MadsVind", 
                  content: imgBlobOutput("https://avatars.githubusercontent.com/u/73589644?s=40&amp;v=4", "@MadsVind")},
                 
                 {type: "txt",
                  href: "email-form.html",             
                  title: "Contact me",              
                  content: "@"}];

function addBlop() {
  main = document.querySelector(body>main);
}

function imgBlobOutput(src, alt) {
  let imgHTML = `<img src=${src}alt=${alt} data-view-component=\"true\" class=\"imgBlob\"> </a>`
  
  retun imgHTML;
}
