//
//  SKDatabase.h
//  LookPrototype
//
//

#import <UIKit/UIKit.h>
#import <sqlite3.h>

@protocol SKDatabaseDelegate <NSObject>
@optional
- (void)databaseTableWasUpdated:(NSString *)table;
@end

@interface SKDatabase : NSObject {
	
	id<SKDatabaseDelegate> __weak delegate;
	sqlite3 *dbh;
	BOOL dynamic;
}

@property (weak) id<SKDatabaseDelegate> delegate;
@property sqlite3 *dbh;
@property BOOL dynamic;

- (id)initWithFile:(NSString *)dbFile;
- (id)initWithReadOnlyFile:(NSString *)dbFile;
- (id)initWithData:(NSData *)data andFile:(NSString *)dbFile;

- (void)close;

- (sqlite3_stmt *)prepare:(NSString *)sql;

- (id)lookupColForSQL:(NSString *)sql;
- (NSDictionary *)lookupRowForSQL:(NSString *)sql;
- (NSArray *)lookupAllForSQL:(NSString *)sql;

- (int)lookupCountWhere:(NSString *)where forTable:(NSString *)table;
- (int)lookupMax:(NSString *)key Where:(NSString *)where forTable:(NSString *)table;
- (int)lookupSum:(NSString *)key Where:(NSString *)where forTable:(NSString *)table;

- (void)insertArray:(NSArray *)dbData forTable:(NSString *)table;
- (void)insertDictionary:(NSDictionary *)dbData forTable:(NSString *)table;

- (void)updateArray:(NSArray *)dbData forTable:(NSString *)table;
- (void)updateArray:(NSArray *)dbData forTable:(NSString *)table where:(NSString *)where;
- (void)updateDictionary:(NSDictionary *)dbData forTable:(NSString *)table;
- (void)updateDictionary:(NSDictionary *)dbData forTable:(NSString *)table where:(NSString *)where;
- (void)updateDictionaryForStringOnly:(NSDictionary *)dbData forTable:(NSString *)table where:(NSString *)where ;
- (void)updateSQL:(NSString *)sql forTable:(NSString *)table;

- (void)deleteWhere:(NSString *)where forTable:(NSString *)table;
- (void) deleteAllFrom:(NSString *)table;

- (BOOL)runDynamicSQL:(NSString *)sql forTable:(NSString *)table;

- (NSString *)escapeString:(NSString *)dirtyString;
- (NSString *)lastData :(NSString *)table;
@end



