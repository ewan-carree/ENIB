from ipywidgets import HTML
from IPython.display import display

def show(parameters,name="name"):
    html = "<table class='table' style='margin-top: 10px'>"
    html += "<tr><th scope='col' style='width: 20%'>{}</th><th scope='col' style='width: 80%'>Value</th></tr>\n".format(name.capitalize())
    for name in parameters:
        html += "<tr><td>{}</td><td>{}</td></tr>\n".format(name,parameters[name])
    html += "</table>"
    display(HTML(html))
