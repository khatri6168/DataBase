//
//  ViewController.swift
//  SqlLiteDataBase_swift
//
//  Created by khatri Jigar on 19/09/18.
//  Copyright © 2018 khatri Jigar. All rights reserved.
//

import UIKit
import SQLite3


class ViewController: UIViewController {
    var db: OpaquePointer?
    var objSkDatabase: SKDatabase?

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        //SET DATA BASE
        objSkDatabase = SKDatabase(file: "UserData.db")

        //INSERT DATA
        let dic = NSMutableDictionary()
        dic.setValue("jay", forKey: "name")
        dic.setValue("jay@gmail.com", forKey: "email")
        dic.setValue("3333", forKey: "phone")
        dic.setValue("welcome", forKey: "password")
        objSkDatabase?.insert(dic as! [AnyHashable : Any], forTable: "user")

        //GET ALL DATA
        var arrDAta = NSArray()
        arrDAta = (objSkDatabase?.lookupAll(forSQL: "SELECT * FROM user"))! as NSArray
        
//        //GET ALL DATA
//        var arrDAta = NSArray()
//        arrDAta = (objSkDatabase?.lookupAll(forSQL: "SELECT * FROM user where (email='khatri@gmail.com' and password='welcome')"))! as NSArray
        
        print(arrDAta)

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

   
}

