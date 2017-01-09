int CreatLine<T, E>::getLength(int a, int b)
{
	int i, j;
	if (i = != -1 && j != -1)
	{
		CreatTable<T, E> *p = head[j].next;
		while (p != NULL&&strcmp(p->name, b) != 0)
		{
			p = p->Link;
		}
		if (p != NULL)
			return p->cost;
		else
			return maxValue;
	}
	return maxValue;
}

void CreatLine<T, E>::pathSearch(int a) // ·����������·��
{
	int n = G.NumberOfVertex();	//�������
	bool *s = new bool[n];
	for (int i = 0; i<n; i++)
	{
		path[i] = -1;
	}
	int i, j, k;
	int w, Min;
	int v, x;
	v = getVnode(a);
	for (i = 0; i<n; i++)
	{
		dist[i] = getWeight(v, i);
		s[i] = false;
		if (i != v&&dist[i] != maxValue) path[i] = v;
		else path[i] = -1;
	}
	s[v] = true; dist[v] = 0;
	for (i = 0; i<n - 1; i++)
	{
		Min = maxValue; int u = v;
		for (j = 0; j<n; j++)
		{
			if (s[j] == false && dist[j]<Min)
			{
				u = j; Min = dist[j];
			}
		}
		s[u] = true;
		for (k = 0; k<n; k++)
		{
			w = getWeight(u, k);
			if (s[k] == false && w<maxValue&&dist[u] + w<dist[k])
			{
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
}
void CreatLine<T, E>::printPath(int v, int w)                        //������·��
{
	v = getVnode(v);
	w = getVnode(w);
	int n = G.NumberOfVertex();	//�������
	int i, k;
	i = 0;
	int *d = new int[n];
	int m = w;
	d[0] = w;
	while (path[m] != -1)
	{
		i++;
		d[i] = path[m];
		m = path[m];
	}
	cout << "·����" << Table[v].key << "��·����" << Table[w].key << "�ľ���·�����£� " << endl;
	while (i >= 0)
	{
		cout << " ·��" << Table[d[i]].key << " ";
		i--;
	}
	cout << "\t���·����" << dist[w] << endl;
}