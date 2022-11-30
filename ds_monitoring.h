#ifndef __DS_MONITORING_H
#define __DS_MONITORING_H

struct ds_monitoring{
	struct xarray *elements;
	unsigned long long total_counts;
	const struct ds_monitoring_operations *dm_ops;
};
struct ds_monitoring_operations{
	unsigned long (*get_index)(void *elem);
	const char * (*get_name)(void *elem);
	void (*print_elem)(unsigned long index,const char *name,unsigned long long count,int percentage);
};
struct ds_monitoring_elem {
	unsigned long key;
	char *name;
	unsigned long long count;
};

#define DS_MONITORING_INIT(xarray, _dm_ops) { .elements = &xarray, .total_counts = 0, .dm_ops = &_dm_ops, }

#define DEFINE_DS_MONITORING_OPS(name, get_idx_fn, get_name_fn, print_fn) static const struct ds_monitoring_operations name##_dm_ops = { .get_index = get_idx_fn, .get_name = get_name_fn, .print_elem = print_fn, }

#define DEFINE_DS_MONITORING(name, get_idx_fn, get_name_fn, print_fn) DEFINE_XARRAY(name##xarray); DEFINE_DS_MONITORING_OPS(name, get_idx_fn, get_name_fn, print_fn); struct ds_monitoring name = DS_MONITORING_INIT(name##xarray, name##_dm_ops);


#define DECLARE_DS_MONITORING(name) extern struct ds_monitoring name;

void find_ds_monitoring(struct ds_monitoring *dm, void *elem);
static void insert_ds_monitoring(struct ds_monitoring *dm, unsigned long index, void *elem);
void print_ds_monitoring(struct ds_monitoring *dm);
void delete_ds_monitoring(struct ds_monitoring *dm);

#endif
