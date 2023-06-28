import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        m = request.form.get("month")
        d = request.form.get("day")
        if name == None or m == None or d == None:
            return redirect("/")

        month = int(m)
        day = int(d)
        if (month > 0 or month < 13):
            db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?);", name, month, day)

        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        sort = request.args.get("sort-by")
        birthdays = {}

        if sort == "date":
            birthdays = db.execute("SELECT name, month, day FROM birthdays ORDER BY month, day;")
        elif sort == "name":
            birthdays = db.execute("SELECT name, month, day FROM birthdays ORDER BY name;")
        else:
            birthdays = db.execute("SELECT name, month, day FROM birthdays;")

        return render_template("index.html", birthdays=birthdays)


