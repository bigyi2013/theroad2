import os
import sqlite3
from flask import Flask, request, session, g, redirect, url_for, abort,\
    render_template, flash
from db import init_db
app = Flask(__name__)

@app.errorhandler(404)
def page_not_found(error):
    return render_template('page_not_found.html'), 404
@app.route('/')
def index():
    return  render_template('index.html')

@app.route('/hello/')
@app.route('/hello/<name>')
def hello(name=None):
    return render_template('hello.html', name=name)

if __name__ == '__main__':
    app.run()

