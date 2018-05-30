from flask import Flask, url_for
from flask import request
from flask import render_template

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')
@app.route('/blog/')
@app.route('/blog')
def blog():
    return render_template('blog.html')
@app.route('/hello/')
@app.route('/hello/<name>')
def hello(name=None):
    return render_template('hello.html', name=name)

