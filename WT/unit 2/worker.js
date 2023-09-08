this.onmessage=(event)=>{
   var rnd=Math.floor(Math.random()*1000)
   postMessage("hello!!"+rnd)
}