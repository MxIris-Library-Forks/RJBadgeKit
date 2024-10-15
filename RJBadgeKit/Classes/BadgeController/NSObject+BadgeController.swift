//
//  NSObject+BadgeController.swift
//  RJBadgeKit
//
//  Created by JH on 2024/10/9.
//

import Foundation

//public protocol BadgeObservable: AnyObject {}
//
//extension NSObject: BadgeObservable {}
//
//private var badgeControllerKey: Void = ()
//
//extension BadgeObservable {
//    public var badgeController: BadgeController<Self> {
//        set {
//            objc_setAssociatedObject(self, &badgeControllerKey, newValue, .OBJC_ASSOCIATION_RETAIN_NONATOMIC)
//        }
//        get {
//            if let badgeController = objc_getAssociatedObject(self, &badgeControllerKey) as? BadgeController<Self> {
//                return badgeController
//            } else {
//                let badgeController = BadgeController(observer: self)
//                objc_setAssociatedObject(self, &badgeControllerKey, badgeController, .OBJC_ASSOCIATION_RETAIN_NONATOMIC)
//                return badgeController
//            }
//        }
//    }
//}
